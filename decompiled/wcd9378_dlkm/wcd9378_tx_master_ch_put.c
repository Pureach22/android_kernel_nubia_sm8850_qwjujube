__int64 __fastcall wcd9378_tx_master_ch_put(__int64 a1, __int64 a2)
{
  __int64 v3; // x9
  __int64 result; // x0
  __int64 v5; // x19
  __int64 v7; // x9
  unsigned int v8; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v9; // [xsp+8h] [xbp-8h]

  v9 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v3 = *(_QWORD *)(a1 + 128);
  result = 4294967274LL;
  v8 = -22;
  if ( v3 )
  {
    v5 = *(_QWORD *)(*(_QWORD *)(v3 + 24) + 152LL);
    if ( v5 )
    {
      wcd9378_tx_get_slave_ch_type_idx(a1 + 32, &v8);
      if ( v8 <= 0xC && (v7 = *(unsigned int *)(a2 + 72), (unsigned int)v7 <= 0xD) )
      {
        result = 0;
        *(_BYTE *)(v5 + v8 + 3292) = wcd9378_swr_master_ch_map[v7];
      }
      else
      {
        result = 4294967274LL;
      }
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
