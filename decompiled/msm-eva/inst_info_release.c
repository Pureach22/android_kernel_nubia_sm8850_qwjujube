__int64 __fastcall inst_info_release(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  __int64 v5; // x19

  if ( (msm_cvp_debug & 4) != 0 && !msm_cvp_debug_out )
  {
    v5 = a2;
    printk(&unk_8CAE2, "info", *(_QWORD *)(a1 + 696), a4);
    a2 = v5;
  }
  *(_QWORD *)(a2 + 32) = 0;
  return 0;
}
