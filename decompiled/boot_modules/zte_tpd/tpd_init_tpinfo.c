__int64 __fastcall tpd_init_tpinfo(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 v4; // x20
  int v6; // w8

  v4 = *(_QWORD *)(a1 + 3072);
  printk(&unk_34878, "tpd_init_tpinfo", a3);
  *(_DWORD *)(a1 + 2872) = 1;
  strcpy((char *)(a1 + 2912), "synaptics_3910V");
  v6 = *(_DWORD *)(*(_QWORD *)v4 + 12LL);
  *(_DWORD *)(a1 + 2908) = 4;
  *(_DWORD *)(a1 + 2888) = v6;
  *(_DWORD *)(a1 + 2892) = __rev16(*(unsigned __int16 *)(*(_QWORD *)v4 + 198LL));
  return 0;
}
