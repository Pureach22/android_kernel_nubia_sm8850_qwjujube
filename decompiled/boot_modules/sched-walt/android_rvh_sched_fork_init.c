void __fastcall android_rvh_sched_fork_init(__int64 a1, char *a2)
{
  char *v2; // x8

  if ( (walt_disabled & 1) == 0 )
  {
    v2 = a2 + 5184;
    if ( a2 == (char *)&init_task )
      v2 = (char *)&vendor_data_pad;
    v2[188] = 0;
    *((_DWORD *)v2 + 46) = 0;
    v2[272] = 0;
    *((_DWORD *)v2 + 84) = 0;
    *((_QWORD *)v2 + 43) = 0;
    *(_QWORD *)(v2 + 191) = 0;
    *(_QWORD *)(v2 + 199) = 0;
    *(_QWORD *)(v2 + 207) = 0;
    v2[215] = 0;
    *((_QWORD *)v2 + 46) = 0xFFFFFFFFLL;
    *((_DWORD *)v2 + 109) = 0;
    *((_QWORD *)v2 + 52) = 0;
    *((_QWORD *)v2 + 53) = 0;
    v2[432] = 0;
    *((_DWORD *)v2 + 110) = 0;
    nbia_fork_init(a2);
  }
}
