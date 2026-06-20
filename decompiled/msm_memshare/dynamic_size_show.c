__int64 __fastcall dynamic_size_show(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 v3; // x8

  v3 = memsh_child;
  if ( *(_QWORD *)(memsh_child + 64) == a1 )
    goto LABEL_11;
  v3 = qword_8900;
  if ( *(_QWORD *)(qword_8900 + 64) == a1 )
    goto LABEL_11;
  v3 = qword_8908;
  if ( *(_QWORD *)(qword_8908 + 64) == a1
    || (v3 = qword_8910, *(_QWORD *)(qword_8910 + 64) == a1)
    || (v3 = qword_8918, *(_QWORD *)(qword_8918 + 64) == a1)
    || (v3 = qword_8920, *(_QWORD *)(qword_8920 + 64) == a1)
    || (v3 = qword_8928, *(_QWORD *)(qword_8928 + 64) == a1)
    || (v3 = qword_8930, *(_QWORD *)(qword_8930 + 64) == a1)
    || (v3 = qword_8938, *(_QWORD *)(qword_8938 + 64) == a1)
    || (v3 = qword_8940, *(_QWORD *)(qword_8940 + 64) == a1) )
  {
LABEL_11:
    if ( v3 )
      return (int)scnprintf(a3, 4096, "%u\n", *(_DWORD *)(v3 + 4));
  }
  dev_err(*(_QWORD *)memsh_drv, "memshare: Read request for invalid client\n");
  return -22;
}
