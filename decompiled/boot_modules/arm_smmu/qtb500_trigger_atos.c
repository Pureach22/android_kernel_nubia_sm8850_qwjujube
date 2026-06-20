unsigned __int64 __fastcall qtb500_trigger_atos(__int64 a1, __int64 a2, int a3, unsigned int a4)
{
  __int64 v5; // x22
  unsigned __int64 v8; // x23
  __int64 v9; // x0
  __int64 v10; // x21
  __int64 v11; // x0
  __int64 v12; // x2
  unsigned __int64 v13; // x19
  unsigned __int64 v14; // x0

  v5 = *(_QWORD *)(a1 + 32);
  v8 = a4 & 9
     | ((((unsigned __int64)a4 >> 2) & 1) << 12) & 0xFFFFFFFFFFFFDFFFLL
     | ((((unsigned __int64)a4 >> 1) & 1) << 13);
  writeq_relaxed_0(a3 & 0x3FF | ((((unsigned __int64)a4 >> 3) & 1) << 20), v5 + 1072);
  writeq_relaxed_0(v8 ^ 0x408, v5 + 1080);
  writeq_relaxed_0(a2, v5 + 1088);
  v9 = writeq_relaxed_0(1, v5 + 1096);
  v10 = ktime_get(v9) + 100000;
  do
  {
    if ( (readq_relaxed_0(v5 + 1104) & 1) == 0 )
    {
      v11 = readq_relaxed_0(v5 + 1112);
      if ( (v11 & 1) == 0 )
        continue;
    }
    v14 = readq_relaxed_0(v5 + 1112);
    v12 = v14;
    if ( (v14 & 1) == 0 )
    {
      v13 = v14 >> 12;
      goto LABEL_11;
    }
    goto LABEL_12;
  }
  while ( ktime_get(v11) <= v10 );
  v12 = readq_relaxed_0(v5 + 1112);
  if ( (v12 & 1) != 0 )
  {
LABEL_12:
    dev_err(*(_QWORD *)(a1 + 16), "ECATS generated a fault interrupt! OUTFLD0 = 0x%llx SID = 0x%x\n", v12, a3);
    v13 = 0;
    goto LABEL_11;
  }
  if ( (unsigned int)__ratelimit(&qtb500_trigger_atos__rs, "qtb500_trigger_atos") )
    dev_err(*(_QWORD *)(a1 + 16), "ECATS translation timed out!\n");
  v13 = 0;
LABEL_11:
  writeq_relaxed_0(0, v5 + 1096);
  return v13;
}
