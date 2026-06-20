__int64 __fastcall qcom_q6v5_prepare(__int64 *a1)
{
  unsigned int v2; // w0
  __int64 v3; // x0
  unsigned int v4; // w0
  __int64 v5; // x0
  __int64 v7; // x8
  unsigned int v8; // w19
  unsigned int v9; // w20

  if ( *((_BYTE *)a1 + 321) == 1 )
  {
    *(_BYTE *)(a1[1] + 1204) = 1;
    *((_BYTE *)a1 + 321) = 0;
  }
  v2 = icc_set_bw(a1[5], 0xFFFFFFFFLL, 0xFFFFFFFFLL);
  if ( (v2 & 0x80000000) != 0 )
  {
    v7 = *a1;
    v8 = v2;
    dev_err(v7, "failed to set bandwidth request\n");
    return v8;
  }
  else
  {
    v3 = a1[4];
    if ( v3
      && (v4 = qmp_send(v3, "{class: image, res: load_state, name: %s, val: %s}", (const char *)a1[36], "on")) != 0 )
    {
      v9 = v4;
      dev_err(*a1, "failed to toggle load state\n");
      icc_set_bw(a1[5], 0, 0);
      return v9;
    }
    else
    {
      v5 = *((unsigned int *)a1 + 19);
      *((_DWORD *)a1 + 36) = 0;
      *((_DWORD *)a1 + 44) = 0;
      *((_BYTE *)a1 + 284) = 1;
      *((_BYTE *)a1 + 136) = 0;
      enable_irq(v5);
      return 0;
    }
  }
}
