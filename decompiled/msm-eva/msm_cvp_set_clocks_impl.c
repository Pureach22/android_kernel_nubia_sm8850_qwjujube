__int64 __fastcall msm_cvp_set_clocks_impl(__int64 a1, unsigned int a2, __int64 a3, __int64 a4)
{
  __int64 v4; // x8
  __int64 v5; // x19
  int v7; // w21
  unsigned __int64 v8; // x25
  __int64 result; // x0
  int v10; // w8
  char v11; // w9
  unsigned __int64 v12; // x8
  unsigned int v13; // w19
  unsigned __int64 StatusReg; // x8
  unsigned int v15; // w20

  v4 = *(_QWORD *)(a1 + 2208);
  LODWORD(v5) = a2;
  v7 = **(_DWORD **)(v4 + 160);
  if ( (msm_cvp_debug & 0x400) != 0 && !msm_cvp_debug_out )
  {
    printk(&unk_9254F, &unk_8DA84, "msm_cvp_set_clocks_impl", a2);
    v4 = *(_QWORD *)(a1 + 2208);
  }
  v8 = *(_QWORD *)(v4 + 280);
  if ( v8 >= v8 + 32LL * *(unsigned int *)(v4 + 288) )
    return 0;
  while ( 1 )
  {
    if ( *(_BYTE *)(v8 + 28) != 1 )
      goto LABEL_7;
    v10 = msm_cvp_clock_voting;
    v11 = BYTE1(msm_cvp_debug);
    *(_DWORD *)(a1 + 24) = v5;
    if ( !v10 )
      v10 = v5;
    v5 = (unsigned int)(3 * v10);
    if ( (v11 & 4) != 0 && !msm_cvp_debug_out )
      break;
    if ( *(_QWORD *)(a1 + 2400) )
      goto LABEL_6;
LABEL_14:
    if ( (msm_cvp_debug & 0x400) != 0 && !msm_cvp_debug_out )
      printk(&unk_830D3, &unk_8DA84, "msm_cvp_set_clocks_impl", a4);
    result = clk_set_rate(*(_QWORD *)(v8 + 16), v5);
    if ( (_DWORD)result )
    {
      if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
      {
        StatusReg = _ReadStatusReg(SP_EL0);
        v15 = result;
        printk(&unk_8AB7D, *(unsigned int *)(StatusReg + 1800), *(unsigned int *)(StatusReg + 1804), &unk_8E7CE);
        return v15;
      }
      return result;
    }
    if ( (msm_cvp_debug & 0x400) != 0 && !msm_cvp_debug_out )
      printk(&unk_971B3, &unk_8DA84, *(_QWORD *)v8, (unsigned int)v5);
LABEL_7:
    v8 += 32LL;
    if ( v8 >= *(_QWORD *)(*(_QWORD *)(a1 + 2208) + 280LL)
             + 32 * (unsigned __int64)*(unsigned int *)(*(_QWORD *)(a1 + 2208) + 288LL) )
      return 0;
  }
  printk(&unk_86426, &unk_8DA84, "msm_cvp_set_clocks_impl", (unsigned int)v5);
  if ( !*(_QWORD *)(a1 + 2400) )
    goto LABEL_14;
LABEL_6:
  result = msm_cvp_mmrm_set_value_in_range(a1, 3 * v7, v5);
  if ( !(_DWORD)result )
    goto LABEL_7;
  if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
  {
    v12 = _ReadStatusReg(SP_EL0);
    v13 = result;
    printk(&unk_90491, *(unsigned int *)(v12 + 1800), *(unsigned int *)(v12 + 1804), &unk_8E7CE);
    return v13;
  }
  return result;
}
