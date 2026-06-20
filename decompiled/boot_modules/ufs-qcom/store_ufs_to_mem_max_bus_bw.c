__int64 __fastcall store_ufs_to_mem_max_bus_bw(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  __int64 v4; // x8
  __int64 v5; // x20
  int v8; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v9; // [xsp+8h] [xbp-8h]

  v9 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = *(_QWORD *)(a1 + 152);
  if ( !v4 )
  {
    __break(0x800u);
    JUMPOUT(0x153F4);
  }
  v5 = *(_QWORD *)(v4 + 184);
  v8 = 0;
  if ( !(unsigned int)kstrtouint(a3, 0, &v8) )
  {
    *(_BYTE *)(v5 + 24) = v8 != 0;
    ((void (__fastcall *)(__int64))ufs_qcom_icc_update_bw)(v5);
  }
  _ReadStatusReg(SP_EL0);
  return a4;
}
