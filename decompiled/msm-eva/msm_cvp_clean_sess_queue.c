__int64 __fastcall msm_cvp_clean_sess_queue(__int64 a1, __int64 a2)
{
  _QWORD *v4; // x23
  _QWORD *v5; // x8
  _QWORD *v6; // x21
  __int64 v7; // x22
  _QWORD *v8; // x9
  __int64 v9; // x8
  unsigned int v16; // w10

  raw_spin_lock(a2);
  if ( *(_DWORD *)(a2 + 8) )
  {
    v4 = (_QWORD *)(a2 + 16);
LABEL_3:
    if ( *(_DWORD *)(a2 + 4) != 1 )
    {
      v5 = (_QWORD *)*v4;
      while ( v5 != v4 )
      {
        v6 = v5;
        v7 = v5[6];
        v5 = (_QWORD *)*v5;
        if ( v7 )
        {
          v8 = (_QWORD *)v6[1];
          if ( (_QWORD *)*v8 == v6 && (_QWORD *)v5[1] == v6 )
          {
            v5[1] = v8;
            *v8 = v5;
          }
          else
          {
            _list_del_entry_valid_or_report(v6);
          }
          *v6 = v6;
          v6[1] = v6;
          --*(_DWORD *)(a2 + 8);
          raw_spin_unlock(a2);
          msm_cvp_unmap_frame(a1, v7);
          v9 = cvp_driver;
          _X9 = (unsigned int *)(cvp_driver + 80);
          __asm { PRFM            #0x11, [X9] }
          do
            v16 = __ldxr(_X9);
          while ( __stxr(v16 - 1, _X9) );
          kmem_cache_free(*(_QWORD *)(v9 + 72));
          raw_spin_lock(a2);
          if ( *(_DWORD *)(a2 + 8) )
            goto LABEL_3;
          return raw_spin_unlock(a2);
        }
      }
    }
  }
  return raw_spin_unlock(a2);
}
