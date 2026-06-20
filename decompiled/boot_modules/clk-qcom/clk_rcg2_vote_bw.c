__int64 __fastcall clk_rcg2_vote_bw(__int64 a1, unsigned __int64 a2)
{
  __int64 v3; // x21
  int v4; // w8
  __int64 v5; // x0
  __int64 v6; // x2
  int v7; // w0
  __int64 v8; // x0
  __int64 v9; // x2
  int v10; // w0
  __int64 v11; // x0
  __int64 v12; // x2
  __int64 result; // x0
  int v14; // w20
  int v15; // w20
  unsigned int v16; // w21
  int v17; // w20
  __int64 v18; // [xsp+8h] [xbp-18h] BYREF
  int v19; // [xsp+10h] [xbp-10h]
  int v20; // [xsp+14h] [xbp-Ch]
  __int64 v21; // [xsp+18h] [xbp-8h]

  v21 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v3 = *(_QWORD *)(a1 + 120);
  v20 = 0;
  if ( a2 )
    v4 = (a2 / 0xF4240) & 0x3FFF | 0x60000000;
  else
    v4 = 1610612736;
  v5 = *(_QWORD *)(v3 + 16);
  v6 = *(unsigned __int8 *)(v3 + 46);
  v19 = v4;
  LOBYTE(v20) = 1;
  v18 = 0;
  v7 = crm_write_bw_vote(v5, 1, v6, &v18);
  if ( v7 )
  {
    v14 = v7;
    if ( !*(_QWORD *)(a1 + 16) )
      clk_hw_get_name(a1);
    printk(&unk_285F5);
    if ( v14 == -110 && (unsigned int)crm_dump_regs(**(_QWORD **)(a1 + 120)) )
    {
      if ( !*(_QWORD *)(a1 + 16) )
        clk_hw_get_name(a1);
      printk(&unk_28CEC);
    }
  }
  v8 = *(_QWORD *)(v3 + 16);
  v9 = *(unsigned __int8 *)(v3 + 46);
  LODWORD(v18) = 1;
  v10 = crm_write_bw_vote(v8, 1, v9, &v18);
  if ( v10 )
  {
    v15 = v10;
    if ( !*(_QWORD *)(a1 + 16) )
      clk_hw_get_name(a1);
    printk(&unk_285F5);
    if ( v15 == -110 && (unsigned int)crm_dump_regs(**(_QWORD **)(a1 + 120)) )
    {
      if ( !*(_QWORD *)(a1 + 16) )
        clk_hw_get_name(a1);
      printk(&unk_28CEC);
    }
  }
  v11 = *(_QWORD *)(v3 + 16);
  v12 = *(unsigned __int8 *)(v3 + 46);
  LODWORD(v18) = 2;
  result = crm_write_bw_vote(v11, 1, v12, &v18);
  if ( (_DWORD)result )
  {
    v16 = result;
    if ( !*(_QWORD *)(a1 + 16) )
      clk_hw_get_name(a1);
    printk(&unk_285F5);
    result = v16;
    if ( v16 == -110 )
    {
      v17 = crm_dump_regs(**(_QWORD **)(a1 + 120));
      result = 4294967186LL;
      if ( v17 )
      {
        if ( !*(_QWORD *)(a1 + 16) )
          clk_hw_get_name(a1);
        printk(&unk_28CEC);
        result = 4294967186LL;
      }
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
