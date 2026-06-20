__int64 __usercall sub_5E674@<X0>(__int64 a1@<X3>, __int64 a2@<X8>)
{
  __int64 v2; // x12

  *(_QWORD *)(v2 + 184) = a2;
  *(_QWORD *)(v2 + 192) = a1;
  return dp_catalog_ctrl_phy_lane_cfg();
}
