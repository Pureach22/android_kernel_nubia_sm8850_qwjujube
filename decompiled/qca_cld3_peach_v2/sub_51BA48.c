__int64 __fastcall sub_51BA48(__int64 a1, __int64 a2, __int64 a3, __int64 a4, __int64 a5, __int64 a6, __int64 a7)
{
  __int64 v7; // x28
  __int64 v8; // x29

  *(_QWORD *)(a7 + 16) = v7;
  *(_QWORD *)(a7 + 24) = v8;
  return dp_tx_remove_vlan_tag();
}
