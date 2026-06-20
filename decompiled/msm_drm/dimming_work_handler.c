__int64 __fastcall dimming_work_handler(__int64 a1, __int64 a2)
{
  __int64 v3; // x0

  v3 = a1 - 2328;
  if ( v3 )
    return zte_set_disp_parameter(v3, 7, *(_DWORD *)(a1 + 112));
  else
    return printk(&unk_214703, a2);
}
