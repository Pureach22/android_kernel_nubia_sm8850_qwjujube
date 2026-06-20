__int64 __fastcall swr_dmic_tx_master_port_get(__int64 a1, __int64 a2)
{
  __int64 v2; // x8
  __int64 v3; // x20
  __int64 result; // x0
  void *v6; // x0
  __int64 v7; // x8
  unsigned int v8; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v9; // [xsp+8h] [xbp-8h]

  v9 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = *(_QWORD *)(a1 + 128);
  v8 = 2;
  if ( !v2 )
  {
    if ( (unsigned int)__ratelimit(&swr_dmic_tx_master_port_get__rs, "swr_dmic_tx_master_port_get") )
    {
      v6 = &unk_7CF2;
      goto LABEL_17;
    }
LABEL_10:
    result = 4294967274LL;
    goto LABEL_11;
  }
  v3 = *(_QWORD *)(*(_QWORD *)(v2 + 24) + 152LL);
  if ( !v3 )
  {
    if ( (unsigned int)__ratelimit(&swr_dmic_tx_master_port_get__rs_39, "swr_dmic_tx_master_port_get") )
    {
      v6 = &unk_807D;
      goto LABEL_17;
    }
    goto LABEL_10;
  }
  result = swr_dmic_tx_get_slave_port_type_idx(a1 + 32, &v8);
  if ( !(_DWORD)result )
  {
    if ( v8 >= 2 )
    {
      if ( (unsigned int)__ratelimit(&swr_dmic_tx_master_port_get__rs_41, "swr_dmic_tx_master_port_get") )
      {
        v6 = &unk_7E02;
LABEL_17:
        printk(v6, "swr_dmic_tx_master_port_get");
        goto LABEL_10;
      }
      goto LABEL_10;
    }
    result = 0;
    if ( (unsigned int)*(unsigned __int8 *)(v3 + v8 + 72) - 45 < 0xE )
      v7 = (unsigned __int8)(*(_BYTE *)(v3 + v8 + 72) - 45) + 1LL;
    else
      v7 = 0;
    *(_QWORD *)(a2 + 72) = v7;
  }
LABEL_11:
  _ReadStatusReg(SP_EL0);
  return result;
}
