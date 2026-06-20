__int64 __fastcall gh_dbl_validate_params(_DWORD *a1, int a2, __int64 a3, __int64 a4, unsigned __int64 a5)
{
  unsigned __int128 *v5; // x13
  __int64 result; // x0
  __int64 v8; // x24
  _DWORD *v9; // x23
  __int64 v12; // x20
  _QWORD *v13; // x19
  __int64 v14; // x0
  unsigned int v15; // w20
  _QWORD *v16; // x8
  __int64 v17; // [xsp+0h] [xbp-30h] BYREF
  __int64 v18; // [xsp+8h] [xbp-28h]
  __int64 v19; // [xsp+10h] [xbp-20h]
  __int64 v20; // [xsp+18h] [xbp-18h]
  __int64 v21; // [xsp+20h] [xbp-10h]
  __int64 v22; // [xsp+28h] [xbp-8h]

  result = 4294967274LL;
  v22 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( !a1 || (unsigned __int64)a1 > 0xFFFFFFFFFFFFF000LL || (unsigned int)(*a1 - 266) < 0xFFFFFFF6 )
    goto LABEL_34;
  v8 = *a1 & 0xF;
  if ( (*a1 & 0xFu) < 0xB )
  {
    v9 = a1;
    v12 = 96 * v8;
    v13 = &gh_dbl_cap_table[12 * v8];
    raw_spin_lock(v13 + 1);
    if ( (_DWORD)v8 != 10 )
    {
      if ( (_DWORD *)*v13 != v9 )
      {
        raw_spin_unlock(v13 + 1);
        printk(&unk_76C6, "gh_dbl_validate_params");
        result = 4294967274LL;
        goto LABEL_34;
      }
      if ( a2 == 1 )
      {
        if ( *((_DWORD *)v13 + 11) )
        {
          if ( (a3 & 0x100000000LL) == 0 )
          {
            raw_spin_unlock(v13 + 1);
            if ( v13[4] == -1 )
            {
              v20 = 0;
              v21 = 0;
              v18 = 0;
              v19 = 0;
              v17 = 0;
              init_wait_entry(&v17, 0);
              while ( 1 )
              {
                v14 = prepare_to_wait_event(v13 + 9, &v17, 1);
                if ( v13[4] != -1 )
                  break;
                if ( v14 )
                  goto LABEL_36;
                schedule();
              }
LABEL_32:
              finish_wait(v13 + 9, &v17);
              goto LABEL_33;
            }
            goto LABEL_33;
          }
          v16 = v13 + 4;
          goto LABEL_28;
        }
LABEL_24:
        v15 = -22;
LABEL_31:
        raw_spin_unlock(v13 + 1);
        result = v15;
LABEL_34:
        _ReadStatusReg(SP_EL0);
        return result;
      }
      if ( (v12 | 0x18uLL) <= 0x3C0 )
      {
        if ( !*((_DWORD *)v13 + 6) )
          goto LABEL_24;
        if ( (a3 & 0x100000000LL) != 0 )
        {
          if ( (v12 | 0x10uLL) <= 0x3C0 )
          {
            v16 = v13 + 2;
LABEL_28:
            if ( *v16 == -1 )
              v15 = -11;
            else
              v15 = 0;
            goto LABEL_31;
          }
        }
        else
        {
          raw_spin_unlock(v13 + 1);
          if ( (v12 | 0x10uLL) <= 0x3C0 )
          {
            if ( v13[2] == -1 )
            {
              v20 = 0;
              v21 = 0;
              v18 = 0;
              v19 = 0;
              v17 = 0;
              init_wait_entry(&v17, 0);
              while ( 1 )
              {
                v14 = prepare_to_wait_event(v13 + 9, &v17, 1);
                if ( v13[2] != -1 )
                  goto LABEL_32;
                if ( v14 )
                {
LABEL_36:
                  if ( !(_DWORD)v14 )
                    break;
                  result = 4294966784LL;
                  goto LABEL_34;
                }
                schedule();
              }
            }
LABEL_33:
            result = 0;
            goto LABEL_34;
          }
        }
      }
    }
    __break(1u);
  }
  __break(0x5512u);
  return gh_dbl_set_mask(__stlxp(__PAIR128__(a5, a5), v5));
}
