__int64 __fastcall hif_ce_dump_target_memory(__int64 a1, int a2, int a3, unsigned int a4)
{
  __int64 result; // x0
  unsigned int v9; // w25
  int v10; // w27
  int v11; // w24
  __int64 v12; // x8
  int v13; // w9
  int v14; // w0
  __int64 v15; // x8
  unsigned int v16; // w22
  unsigned int v17; // w24
  __int64 v18; // x8
  int v19; // w0
  int v20; // [xsp+Ch] [xbp-14h] BYREF
  _QWORD v21[2]; // [xsp+10h] [xbp-10h] BYREF

  v21[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v20 = 0;
  result = hif_target_sleep_state_adjust(a1, 0, 1);
  if ( (result & 0x80000000) == 0 )
  {
    if ( a4 )
    {
      v9 = 0;
      v10 = a3;
      do
      {
        v12 = *(_QWORD *)(a1 + 40);
        v13 = *(unsigned __int8 *)(a1 + 31089);
        v21[0] = 0;
        v14 = v12 + v10 + v9;
        v15 = *(_QWORD *)(a1 + 30720);
        if ( v13 == 1 && (v16 = v14 - v15, (unsigned int)(v14 - v15) >> 19) )
        {
          pld_lock_reg_window(*(_QWORD *)(a1 + 30760), v21);
          v17 = (v16 >> 19) & 0x3F | 0x40000000;
          writel(v17, *(_QWORD *)(a1 + 30720) + 12920LL);
          v18 = *(_QWORD *)(a1 + 30720);
          *(_DWORD *)(a1 + 31092) = (v16 >> 19) & 0x3F;
          v19 = readl(v18 + 12920);
          if ( v19 != v17 )
            qdf_trace_msg(
              61,
              2,
              "%s: Reg write failed. write val 0x%x read val 0x%x offset 0x%x",
              "hif_reg_write_result_check",
              v17,
              v19,
              12920);
          v11 = readl(*(_QWORD *)(a1 + 30720) + (*(_QWORD *)&v16 & 0x7FFFFLL) + 0x80000);
          pld_unlock_reg_window(*(_QWORD *)(a1 + 30760), v21);
        }
        else
        {
          v11 = ((__int64 (*)(void))readl)();
        }
        v20 = v11;
        qdf_mem_copy(a2 + v9, (int)&v20, 4u);
        v9 += 4;
      }
      while ( v9 < a4 );
    }
    result = hif_target_sleep_state_adjust(a1, 1, 0);
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
