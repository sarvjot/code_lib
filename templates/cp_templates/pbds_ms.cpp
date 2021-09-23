#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;

#define ordered_ms tree<pair<big, big>, null_type, less<pair<big, big>>, rb_tree_tag, tree_order_statistics_node_update>