void *__fastcall dp_tx_remove_vlan_tag(__int64 a1, __int64 a2)
{
  const void *v3; // x1
  __int64 v4; // x8
  void *result; // x0
  _QWORD v6[2]; // [xsp+0h] [xbp-20h] BYREF
  __int16 v7; // [xsp+10h] [xbp-10h]
  __int64 v8; // [xsp+18h] [xbp-8h]

  v8 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v3 = *(const void **)(a2 + 224);
  v7 = 0;
  v6[0] = 0;
  v6[1] = 0;
  qdf_mem_copy(v6, v3, 0x12u);
  v4 = *(_QWORD *)(a2 + 40);
  if ( v4 )
    *(_QWORD *)(a2 + 40) = v4 + 4;
  skb_pull(a2, 4);
  result = qdf_mem_copy(*(void **)(a2 + 224), v6, 0xCu);
  _ReadStatusReg(SP_EL0);
  return result;
}
