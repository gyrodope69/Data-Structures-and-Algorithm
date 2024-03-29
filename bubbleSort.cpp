// templated SDN
// def handle_spoof(self, attacker_ip, attacker_mac, msg):
//     actions = []
//     in_port = msg.match['in_port']
//     datapath = msg.datapath
//     ofproto = datapath.ofproto
//     parser = datapath.ofproto_parser
//     inst = [parser.OFPInstructionActions(ofproto.OFPIT_CLEAR_ACTIONS, [])]
//     match = parser.OFPMatch(in_port=in_port, eth_src=attacker_mac, ipv4_src=attacker_ip)
//     mod = parser.OFPFlowMod(
//         datapath=datapath, match=match, idle_timeout=60, hard_timeout=60, priority=20, instructions=inst
//     )
//     datapath.send_msg(mod)
//     self.logger.info("\033[1;31m" + "Blocked traffic from IP %s and MAC %s on port %s" + "\033[0m", attacker_ip, attacker_mac, in_port)

def handle_spoof(self, mac, msg):
    actions = []
    in_port = msg.match['in_port']
    datapath = msg.datapath
    ofproto = datapath.ofproto
    parser = datapath.ofproto_parser
    inst = [parser.OFPInstructionActions(ofproto.OFPIT_CLEAR_ACTIONS, [])]
    match = parser.OFPMatch(in_port=in_port)
    
    # Block the specific port
    block_actions = [parser.OFPActionOutput(ofproto.OFPP_NONE, 0)]
    block_inst = [parser.OFPInstructionActions(ofproto.OFPIT_APPLY_ACTIONS, block_actions)]
    block_mod = parser.OFPFlowMod(datapath=datapath, match=match, priority=20, instructions=block_inst)
    
    # Install flow to block the port
    datapath.send_msg(block_mod)
    
    # Set idle_timeout and hard_timeout for blocking
    mod = parser.OFPFlowMod(datapath=datapath, match=match, idle_timeout=60, hard_timeout=60, priority=10, instructions=inst)
    
    # Sending the flow mod
    datapath.send_msg(mod)
    
    self.logger.info("\033[1;31m" + "Installed an entry to block ARP spoofing on port %s for 60 seconds" + "\033[0m", in_port)




// code for bubble sort in array 


#include <bits/stdc++.h>
using namespace std;


int main()
{
    cout << "Enter number of elements:\n";
    int n;
    cin >> n;
    int arr[n];
    cout << "\nEnter elements in array:\n";
    for (int i = 0; i < n; i++)
    {
        cin >>arr[i];
    }                 
    // bubbleSort(arr,n);
    int temp = 0;
    int counter = 1;
    while (counter < n)
    {
        for (int i = 0; i < n - 1; i++)
        {
            if (arr[i] > arr[i + 1])
            {
                temp = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = temp;
            }
        }
        counter++;
    }
    cout << "The sorted array is :\n";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}
