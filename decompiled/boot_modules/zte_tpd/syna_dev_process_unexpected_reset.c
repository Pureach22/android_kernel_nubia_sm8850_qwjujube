__int64 __fastcall syna_dev_process_unexpected_reset(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  void *v5; // x0

  if ( !a4 )
  {
    v5 = &unk_38D56;
    goto LABEL_6;
  }
  if ( *(_DWORD *)(a4 + 1404) == 1 )
  {
    printk(&unk_32499, "syna_dev_process_unexpected_reset", a3);
    if ( *(_QWORD *)(a4 + 1352) )
    {
      if ( !*(_DWORD *)(a4 + 1312) )
      {
        *(_DWORD *)(a4 + 1312) = 1;
        queue_work_on(32);
      }
      return 0;
    }
    v5 = &unk_3BEBC;
LABEL_6:
    printk(v5, "syna_dev_process_unexpected_reset", a3);
    return 4294967274LL;
  }
  return 0;
}
