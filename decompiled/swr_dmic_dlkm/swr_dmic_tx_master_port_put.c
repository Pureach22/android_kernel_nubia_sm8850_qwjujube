__int64 __fastcall swr_dmic_tx_master_port_put(__int64 a1, __int64 a2)
{
  __int64 v2; // x8
  __int64 v3; // x19
  __int64 result; // x0
  void *v6; // x0
  __int64 v7; // x9
  unsigned int v8; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v9; // [xsp+8h] [xbp-8h]

  v9 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = *(_QWORD *)(a1 + 128);
  v8 = 2;
  if ( !v2 )
  {
    if ( (unsigned int)__ratelimit(&swr_dmic_tx_master_port_put__rs, "swr_dmic_tx_master_port_put") )
    {
      v6 = &unk_7CF2;
      goto LABEL_15;
    }
LABEL_10:
    result = 4294967274LL;
    goto LABEL_11;
  }
  v3 = *(_QWORD *)(*(_QWORD *)(v2 + 24) + 152LL);
  if ( !v3 )
  {
    if ( (unsigned int)__ratelimit(&swr_dmic_tx_master_port_put__rs_45, "swr_dmic_tx_master_port_put") )
    {
      v6 = &unk_807D;
      goto LABEL_15;
    }
    goto LABEL_10;
  }
  result = swr_dmic_tx_get_slave_port_type_idx(a1 + 32, &v8);
  if ( !(_DWORD)result )
  {
    if ( v8 < 2 )
    {
      v7 = *(unsigned int *)(a2 + 72);
      if ( (unsigned int)v7 <= 0xE )
      {
        result = 0;
        *(_BYTE *)(v3 + v8 + 72) = swr_master_channel_map[v7];
        goto LABEL_11;
      }
      goto LABEL_10;
    }
    if ( (unsigned int)__ratelimit(&swr_dmic_tx_master_port_put__rs_46, "swr_dmic_tx_master_port_put") )
    {
      v6 = &unk_7E02;
LABEL_15:
      printk(v6, "swr_dmic_tx_master_port_put");
      goto LABEL_10;
    }
    goto LABEL_10;
  }
LABEL_11:
  _ReadStatusReg(SP_EL0);
  return result;
}
