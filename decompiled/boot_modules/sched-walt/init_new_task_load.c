__int64 __fastcall init_new_task_load(char *a1)
{
  unsigned __int64 StatusReg; // x12
  char *v2; // x19
  _DWORD *v3; // x20
  unsigned __int64 v4; // x8
  unsigned int v5; // w10
  unsigned int v6; // w9
  int v7; // w11
  int v8; // w8
  __int64 result; // x0
  unsigned int v10; // w8

  StatusReg = _ReadStatusReg(SP_EL0);
  if ( a1 == (char *)&init_task )
    v2 = (char *)&vendor_data_pad;
  else
    v2 = a1 + 5184;
  if ( (_UNKNOWN *)StatusReg == &init_task )
    v3 = &vendor_data_pad;
  else
    v3 = (_DWORD *)(StatusReg + 5184);
  LODWORD(v4) = sched_init_task_load_windows;
  v5 = v3[54];
  *((_DWORD *)v2 + 54) = 0;
  LOWORD(v6) = sched_init_task_load_windows_scaled;
  *((_QWORD *)v2 + 30) = 0;
  *((_QWORD *)v2 + 31) = v2 + 248;
  *((_QWORD *)v2 + 32) = v2 + 248;
  v7 = *(_DWORD *)(StatusReg + 40);
  v2[360] = 0;
  *(_QWORD *)(v2 + 132) = 0;
  *((_DWORD *)v2 + 88) = v7;
  *((_DWORD *)v2 + 89) = -1;
  *((_QWORD *)v2 + 21) = 0;
  *(_QWORD *)(v2 + 276) = 0xFFFFFFFF00000000LL;
  *((_DWORD *)v2 + 6) = 0;
  *((_QWORD *)v2 + 1) = 0;
  *((_QWORD *)v2 + 2) = 0;
  *((_DWORD *)v2 + 91) = -1;
  v2[386] = 0;
  *((_WORD *)v2 + 194) = 0;
  *((_DWORD *)v2 + 98) = 0;
  *((_QWORD *)v2 + 33) = 0;
  *((_WORD *)v2 + 78) = 0;
  *(_QWORD *)(v2 + 148) = 0;
  *(_QWORD *)(v2 + 140) = 0;
  *(_QWORD *)(v2 + 92) = 0;
  *(_QWORD *)(v2 + 84) = 0;
  *(_QWORD *)(v2 + 76) = 0;
  *(_QWORD *)(v2 + 68) = 0;
  *(_QWORD *)(v2 + 124) = 0;
  *(_QWORD *)(v2 + 116) = 0;
  *(_QWORD *)(v2 + 108) = 0;
  *(_QWORD *)(v2 + 100) = 0;
  if ( v5 )
  {
    v4 = (unsigned int)sched_ravg_window * (unsigned __int64)v5 / 0x64;
    v6 = (unsigned int)v4 / walt_scale_demand_divisor;
  }
  *((_DWORD *)v2 + 7) = v4;
  *((_DWORD *)v2 + 8) = v4;
  *((_DWORD *)v2 + 9) = v4;
  *((_DWORD *)v2 + 10) = v4;
  *((_DWORD *)v2 + 11) = v4;
  *((_DWORD *)v2 + 12) = v4;
  *((_DWORD *)v2 + 13) = v4;
  v8 = sysctl_sched_task_unfilter_period;
  *((_WORD *)v2 + 79) = v6;
  *((_WORD *)v2 + 80) = 0;
  *((_DWORD *)v2 + 55) = v8;
  *(_WORD *)(v2 + 189) = 0;
  *((_QWORD *)v2 + 36) = v2 + 288;
  *((_QWORD *)v2 + 37) = v2 + 288;
  *((_QWORD *)v2 + 38) = 0;
  *((_QWORD *)v2 + 39) = 0;
  *((_QWORD *)v2 + 40) = 0;
  *((_QWORD *)v2 + 41) = 0xFFFFFFFFLL;
  v2[384] = 0;
  v2[188] = 0;
  *((_DWORD *)v2 + 46) = 0;
  v2[272] = 0;
  *((_DWORD *)v2 + 84) = 0;
  *((_QWORD *)v2 + 43) = 0;
  v2[215] = 0;
  *(_QWORD *)(v2 + 207) = 0;
  *(_QWORD *)(v2 + 199) = 0;
  *(_QWORD *)(v2 + 191) = 0;
  *((_QWORD *)v2 + 46) = 0xFFFFFFFFLL;
  *((_QWORD *)v2 + 47) = 0;
  *((_DWORD *)v2 + 109) = 0;
  v2[432] = 0;
  *((_QWORD *)v2 + 52) = 0;
  *((_QWORD *)v2 + 53) = 0;
  *((_DWORD *)v2 + 110) = 0;
  result = nbia_fork_init(a1);
  v10 = *(_DWORD *)v2 & 0xFFFFFFEC;
  v2[385] = *((_BYTE *)v3 + 385);
  *(_DWORD *)v2 = v10 | 1;
  return result;
}
