__int64 __fastcall _try_to_resume(__int64 a1, int a2, char a3, __int64 a4)
{
  int v4; // w24
  int v5; // w25
  __int64 v10; // x0
  unsigned __int64 *v11; // x10
  unsigned __int64 *v12; // x21
  unsigned __int64 *v13; // t1
  __int64 v14; // x9
  unsigned int v15; // w22
  __int64 *v16; // x11
  __int64 *v17; // x12
  unsigned __int64 v18; // x13
  _QWORD *v19; // x14
  int v20; // w15
  unsigned __int64 v21; // x16
  unsigned __int64 *v22; // x28
  unsigned __int64 v23; // x8
  __int64 v24; // x17
  __int64 v25; // x16
  unsigned __int64 **v26; // x8
  unsigned __int64 v27; // x16
  __int64 v28; // x8
  unsigned __int64 v29; // x2
  unsigned __int64 *v30; // x1
  unsigned __int64 v37; // x17

  v4 = *(_DWORD *)(a1 + 68);
  v5 = *(_DWORD *)(a1 + 72);
  v10 = raw_spin_lock_irqsave(&state_lock);
  v13 = *(unsigned __int64 **)(a1 + 120);
  v12 = (unsigned __int64 *)(a1 + 120);
  v11 = v13;
  v14 = v10;
  v15 = 0;
  if ( v13 != v12 )
  {
    v16 = &cpus_paused_by_us;
    v17 = &cpus_part_paused_by_us;
    v18 = 0xDEAD000000000100LL;
    v19 = &_cpu_active_mask;
    v20 = v5 + 1;
    do
    {
      if ( !--v20 )
        break;
      v21 = *((unsigned int *)v11 - 4);
      v22 = (unsigned __int64 *)*v11;
      v23 = v21 >> 6;
      v24 = 1LL << v21;
      if ( (((1LL << v21) & v16[v21 >> 6]) != 0 || (v17[v23] & v24) != 0)
        && ((v24 & v19[v23]) == 0 || (_cpu_halt_mask[v23] & v24) != 0 || (_cpu_partial_halt_mask[v23] & v24) != 0)
        && ((a3 & 1) != 0 || (*((_BYTE *)v11 - 12) & 1) == 0) )
      {
        if ( v15 + v4 == a2 )
          break;
        v25 = 1LL << v21;
        _X8 = (unsigned __int64 *)(a4 + 8 * v23);
        __asm { PRFM            #0x11, [X8] }
        do
          v37 = __ldxr(_X8);
        while ( __stxr(v37 | v25, _X8) );
        v26 = (unsigned __int64 **)v11[1];
        if ( *v26 == v11 && (v27 = *v11, *(unsigned __int64 **)(*v11 + 8) == v11) )
        {
          *(_QWORD *)(v27 + 8) = v26;
          *v26 = (unsigned __int64 *)v27;
        }
        else
        {
          _list_del_entry_valid_or_report(v11);
        }
        v28 = *(v11 - 1);
        ++v15;
        *v11 = v18;
        v11[1] = v18 + 34;
        v29 = v28 + 120;
        v30 = *(unsigned __int64 **)(v28 + 128);
        if ( v11 == (unsigned __int64 *)(v28 + 120) || v30 == v11 || *v30 != v29 )
        {
          _list_add_valid_or_report(v11, v30, v29);
        }
        else
        {
          *(_QWORD *)(v28 + 128) = v11;
          *v11 = v29;
          v11[1] = (unsigned __int64)v30;
          *v30 = (unsigned __int64)v11;
        }
      }
      v11 = v22;
    }
    while ( v22 != v12 );
  }
  raw_spin_unlock_irqrestore(&state_lock, v14);
  return v15;
}
