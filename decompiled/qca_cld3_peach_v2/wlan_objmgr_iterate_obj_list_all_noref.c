__int64 __fastcall wlan_objmgr_iterate_obj_list_all_noref(__int64 a1, int a2, void (__fastcall *a3)(_QWORD))
{
  int v6; // w21
  __int64 v7; // x8
  __int64 v8; // x24
  __int64 i; // x25
  int v10; // w0
  _QWORD *v11; // x27
  bool v12; // zf
  _QWORD *v13; // x22
  int v14; // w0
  int v15; // w23
  __int64 v16; // x8
  __int64 result; // x0
  _QWORD v18[2]; // [xsp+0h] [xbp-10h] BYREF

  v18[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  wlan_psoc_obj_lock(a1);
  if ( a2 != 1 )
  {
    if ( a2 == 2 )
    {
      v6 = *(unsigned __int16 *)(a1 + 54);
      if ( *(_WORD *)(a1 + 54) )
      {
        if ( *(_QWORD *)(a1 + 72) )
        {
          if ( *((_DWORD *)a3 - 1) != -204971199 )
            __break(0x8234u);
          a3(a1);
        }
        if ( v6 != 1 )
        {
          if ( *(_QWORD *)(a1 + 80) )
          {
            if ( *((_DWORD *)a3 - 1) != -204971199 )
              __break(0x8234u);
            a3(a1);
          }
          if ( v6 != 2 )
          {
            if ( *(_QWORD *)(a1 + 88) )
            {
              if ( *((_DWORD *)a3 - 1) != -204971199 )
                __break(0x8234u);
              a3(a1);
            }
            if ( v6 != 3 )
            {
              if ( *(_QWORD *)(a1 + 96) )
              {
                if ( *((_DWORD *)a3 - 1) != -204971199 )
                  __break(0x8234u);
                a3(a1);
              }
              if ( v6 != 4 )
              {
                if ( *(_QWORD *)(a1 + 104) )
                {
                  if ( *((_DWORD *)a3 - 1) != -204971199 )
                    __break(0x8234u);
                  a3(a1);
                }
                if ( v6 != 5 )
                {
                  if ( *(_QWORD *)(a1 + 112) )
                  {
                    if ( *((_DWORD *)a3 - 1) != -204971199 )
                      __break(0x8234u);
                    a3(a1);
                  }
                  if ( v6 != 6 )
                  {
                    __break(0x5512u);
                    goto LABEL_35;
                  }
                }
              }
            }
          }
        }
      }
    }
    else
    {
      v8 = a1 + 128;
      qdf_spin_lock_bh_2(a1 + 1664);
      for ( i = 0; i != 64; ++i )
      {
        v18[0] = 0;
        v10 = qdf_list_peek_front((_QWORD *)(v8 + 24 * i), v18);
        v11 = (_QWORD *)v18[0];
        if ( v10 )
          v12 = 1;
        else
          v12 = v18[0] == 0;
        if ( !v12 )
        {
          do
          {
            v13 = v11;
            v18[0] = 0;
            v14 = qdf_list_peek_next((_QWORD *)(v8 + 24 * i), v11, v18);
            v11 = (_QWORD *)v18[0];
            v15 = v14;
            if ( *((_DWORD *)a3 - 1) != -204971199 )
              __break(0x8234u);
            ((void (__fastcall *)(__int64, _QWORD *, _QWORD))a3)(a1, v13, 0);
          }
          while ( !v15 && v11 );
        }
      }
      v16 = *(_QWORD *)(a1 + 1672);
      if ( (v16 & 1) != 0 )
      {
        *(_QWORD *)(a1 + 1672) = v16 & 0xFFFFFFFFFFFFFFFELL;
        raw_spin_unlock_bh(a1 + 1664);
        v7 = *(_QWORD *)(a1 + 2824);
        if ( (v7 & 1) == 0 )
          goto LABEL_54;
        goto LABEL_57;
      }
      raw_spin_unlock(a1 + 1664);
    }
LABEL_53:
    v7 = *(_QWORD *)(a1 + 2824);
    if ( (v7 & 1) == 0 )
      goto LABEL_54;
LABEL_57:
    *(_QWORD *)(a1 + 2824) = v7 & 0xFFFFFFFFFFFFFFFELL;
    result = raw_spin_unlock_bh(a1 + 2816);
    goto LABEL_55;
  }
LABEL_35:
  if ( !*(_QWORD *)(a1 + 64) )
    goto LABEL_53;
  if ( *((_DWORD *)a3 - 1) != -204971199 )
    __break(0x8234u);
  a3(a1);
  v7 = *(_QWORD *)(a1 + 2824);
  if ( (v7 & 1) != 0 )
    goto LABEL_57;
LABEL_54:
  result = raw_spin_unlock(a1 + 2816);
LABEL_55:
  _ReadStatusReg(SP_EL0);
  return result;
}
