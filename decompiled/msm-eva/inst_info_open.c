__int64 __fastcall inst_info_open(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  __int64 v5; // x19
  __int64 v6; // x20

  if ( (msm_cvp_debug & 4) != 0 && !msm_cvp_debug_out )
  {
    v5 = a1;
    v6 = a2;
    printk(&unk_926FD, "info", *(_QWORD *)(a1 + 696), a4);
    a1 = v5;
    a2 = v6;
  }
  *(_QWORD *)(a2 + 32) = *(_QWORD *)(a1 + 696);
  return 0;
}
