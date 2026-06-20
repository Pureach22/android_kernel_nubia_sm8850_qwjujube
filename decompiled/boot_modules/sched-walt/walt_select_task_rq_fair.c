void __fastcall walt_select_task_rq_fair(
        __int64 a1,
        unsigned __int64 a2,
        unsigned int a3,
        __int64 a4,
        __int64 a5,
        _DWORD *a6,
        _BYTE *a7,
        char *a8)
{
  _BOOL4 v8; // w8
  unsigned __int64 *v9; // x3

  if ( (walt_disabled & 1) == 0 )
  {
    v8 = (a5 & 0x10) != 0 && ((*(_DWORD *)(_ReadStatusReg(SP_EL0) + 68) >> 2) & 1) == 0;
    v9 = (unsigned __int64 *)*(unsigned int *)(a2 + 2552);
    *(_DWORD *)(a2 + 2552) = 0;
    *a6 = walt_find_energy_efficient_cpu(a2, (char *)a3, (_QWORD *)v8, v9, a5, a6, a7, a8);
  }
}
