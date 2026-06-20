__int64 __fastcall fastrpc_get_domain_pid_info(__int64 a1, __int64 *a2, int *a3)
{
  _DWORD *v6; // x19
  __int64 v7; // x26
  __int64 v8; // x0
  __int64 v9; // x1
  __int64 *v10; // x28
  int v11; // w24
  int v12; // w27
  int v13; // w8
  int v14; // w3
  int v15; // w28
  __int64 v16; // x0
  __int64 v17; // x23
  int v18; // w8
  int v19; // w8
  int v20; // w0
  unsigned __int64 StatusReg; // x23
  __int64 v22; // x24
  __int64 (__fastcall *v23)(_QWORD, _QWORD); // x0
  __int64 v25; // [xsp+8h] [xbp-8h]

  *a2 = 0;
  *a3 = 0;
  v6 = (_DWORD *)_kmalloc_cache_noprof(_kmalloc_noprof, 3520, 128);
  if ( v6 )
  {
    while ( 2 )
    {
      v7 = *(_QWORD *)(a1 + 176);
      if ( v7 )
      {
        a1 = 51600;
        v8 = raw_spin_lock_irqsave(v7 + 51600);
        v9 = v8;
        v10 = *(__int64 **)(v7 + 51648);
        if ( v10 != (__int64 *)(v7 + 51648) )
        {
          v11 = 0;
          v12 = 0;
          v25 = v8;
          do
          {
            v13 = *((_DWORD *)v10 + 67);
            if ( (v13 == 9 || v13 == 7) && *((_DWORD *)v10 + 157) == 2 )
            {
              if ( v11 > 31 )
              {
                v11 = -28;
                goto LABEL_26;
              }
              if ( (unsigned __int64)(4LL * v11) > 0x80 )
                goto LABEL_23;
              v14 = *((_DWORD *)v10 + 62);
              a1 = (unsigned int)(v11 + 1);
              v6[v11++] = v14;
              v12 += snprintf(nullptr, 0, "%d", v14) + 1;
            }
            v10 = (__int64 *)*v10;
          }
          while ( v10 != (__int64 *)(v7 + 51648) );
          if ( v11 )
          {
            v15 = v12 + 1;
            v16 = _kmalloc_noprof(v12 + 1, 2336);
            v17 = v16;
            if ( !v16 )
            {
              v11 = -12;
              goto LABEL_26;
            }
            v18 = *a3;
            if ( v11 >= 1 )
            {
              v18 = *a3 + snprintf((char *)(v16 + v18), v15 - v18, "%d", *v6);
              *a3 = v18;
              if ( v11 != 1 )
              {
                a1 = 1;
                while ( 1 )
                {
                  v19 = *a3 + snprintf((char *)(v17 + v18), v15 - v18, ",");
                  *a3 = v19;
                  if ( (a1 & 0x3FFFFFFFFFFFFFE0LL) != 0 )
                    break;
                  v20 = snprintf((char *)(v17 + v19), v15 - v19, "%d", v6[a1++]);
                  v18 = *a3 + v20;
                  *a3 = v18;
                  if ( v11 == a1 )
                    goto LABEL_20;
                }
LABEL_23:
                __break(1u);
                StatusReg = _ReadStatusReg(SP_EL0);
                v22 = *(_QWORD *)(StatusReg + 80);
                v23 = _kmalloc_noprof;
                *(_QWORD *)(StatusReg + 80) = &fastrpc_get_domain_pid_info__alloc_tag;
                v6 = (_DWORD *)_kmalloc_cache_noprof(v23, 3520, 128);
                *(_QWORD *)(StatusReg + 80) = v22;
                if ( v6 )
                  continue;
                return (unsigned int)-12;
              }
            }
LABEL_20:
            snprintf((char *)(v17 + v18), v15 - v18, "\n");
            v11 = 0;
            ++*a3;
            *a2 = v17;
          }
LABEL_26:
          v9 = v25;
          goto LABEL_27;
        }
        v11 = 0;
LABEL_27:
        raw_spin_unlock_irqrestore(v7 + 51600, v9);
      }
      else
      {
        v11 = -22;
      }
      break;
    }
    kfree(v6);
    return (unsigned int)v11;
  }
  return (unsigned int)-12;
}
