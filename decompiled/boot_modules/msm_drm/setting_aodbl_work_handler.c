__int64 __fastcall setting_aodbl_work_handler(__int64 a1, __int64 a2)
{
  __int64 v2; // x19
  __int64 result; // x0
  unsigned int v5; // w2

  v2 = a1 - 2504;
  if ( a1 == 2504 )
    return printk(&unk_214703, a2);
  result = printk(&unk_225F1D, *(unsigned int *)(a1 - 180));
  v5 = *(_DWORD *)(a1 - 180);
  if ( v5 )
    return zte_set_disp_parameter(v2, 4, v5);
  return result;
}
