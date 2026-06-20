__int64 __fastcall clk_rcg2_crmb_set_crmb_rate(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        unsigned int a4,
        int a5,
        unsigned int a6,
        unsigned int a7)
{
  unsigned int v7; // w9
  __int64 v8; // x8
  int v9; // w11
  __int64 v11; // x0
  int v12; // w20
  __int64 result; // x0
  _DWORD v14[3]; // [xsp+8h] [xbp-18h] BYREF
  int v15; // [xsp+14h] [xbp-Ch]
  __int64 v16; // [xsp+18h] [xbp-8h]

  v16 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v7 = *(unsigned __int8 *)(a1 + 130);
  v8 = *(_QWORD *)(a1 + 120);
  v15 = 0;
  if ( v7 <= a4 )
  {
    result = -22;
  }
  else
  {
    v9 = *(unsigned __int8 *)(a1 + 129);
    v11 = *(_QWORD *)(v8 + 16);
    v14[0] = a5;
    v14[1] = v9 + a4;
    LOBYTE(v15) = 1;
    v14[2] = ((unsigned int)((1125899907 * (unsigned __int64)a6) >> 32) >> 4) & 0x7FFC000 | (a7 / 0xF4240) | 0x60000000;
    v12 = crm_write_bw_vote(v11, a2, a3, v14);
    if ( v12 )
    {
      if ( !*(_QWORD *)(a1 + 16) )
        clk_hw_get_name(a1);
      printk(&unk_286E7);
      if ( v12 == -110 )
        clk_rcg2_crm_err_dump(a1);
    }
    result = v12;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
