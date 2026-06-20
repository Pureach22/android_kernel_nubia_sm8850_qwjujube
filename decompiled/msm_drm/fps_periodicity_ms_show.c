__int64 __fastcall fps_periodicity_ms_show(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 v3; // x8

  if ( a1 && a3 )
  {
    v3 = *(_QWORD *)(a1 + 152);
    if ( v3 )
      return (int)scnprintf(a3, 4096, "%d\n", *(_DWORD *)(v3 + 4468) / 0x3E8u);
    else
      return -22;
  }
  else
  {
    printk(&unk_2120FD, "fps_periodicity_ms_show");
    return -11;
  }
}
