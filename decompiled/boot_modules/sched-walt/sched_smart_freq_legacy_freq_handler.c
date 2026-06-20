__int64 __fastcall sched_smart_freq_legacy_freq_handler(__int64 a1, __int64 a2, __int64 a3, __int64 a4, __int64 a5)
{
  void *v5; // x21
  __int16 v6; // w9
  __int64 result; // x0
  __int64 v8; // x19
  unsigned __int64 v9; // x20
  unsigned int v10; // w9
  __int64 v11; // x9
  _BOOL4 v12; // w8
  unsigned __int64 v13; // x12
  int *v14; // x10
  unsigned __int64 v15; // x10
  unsigned __int64 v16; // x9
  int *v17; // x11
  __int64 v18; // x17
  __int64 v19; // [xsp+8h] [xbp-98h] BYREF
  _QWORD *v20; // [xsp+10h] [xbp-90h]
  __int64 v21; // [xsp+18h] [xbp-88h]
  __int64 v22; // [xsp+20h] [xbp-80h]
  __int64 v23; // [xsp+28h] [xbp-78h]
  __int64 v24; // [xsp+30h] [xbp-70h]
  __int64 v25; // [xsp+38h] [xbp-68h]
  _QWORD v26[12]; // [xsp+40h] [xbp-60h] BYREF

  v26[11] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v19 = 0;
  v20 = v26;
  v5 = *(void **)(a1 + 8);
  v25 = 0;
  memset(v26, 255, 88);
  v22 = 0;
  v21 = 88;
  v6 = *(_WORD *)(a1 + 20);
  v23 = 0;
  v24 = 0;
  WORD2(v21) = v6;
  if ( smart_freq_init_done != 1 )
  {
LABEL_22:
    result = 4294967274LL;
    goto LABEL_23;
  }
  if ( (_DWORD)a2 )
  {
    result = proc_dointvec(&v19, a2, a3, a4, a5);
    if ( !(_DWORD)result )
    {
      v8 = 0;
      v9 = 0;
      while ( 1 )
      {
        v10 = *((_DWORD *)v26 + v8);
        if ( v10 == -1 )
          break;
        if ( (v8 & 1) == 0 )
        {
          if ( v10 > 0xA )
            goto LABEL_22;
          if ( !v10 )
          {
            if ( (unsigned __int64)(v8 + 1) > 0x15 )
              goto LABEL_44;
            if ( *((_DWORD *)v26 + v8 + 1) != -1 )
              v9 = *((int *)v26 + v8 + 1);
          }
        }
        if ( ++v8 == 22 )
          goto LABEL_16;
      }
      if ( (v8 & 1) == 0 )
      {
LABEL_16:
        mutex_lock(&freq_reason_mutex);
        if ( v5 == &sysctl_legacy_freq_levels_cluster0 )
        {
          v11 = 0;
          v12 = 1;
        }
        else if ( v5 == &sysctl_legacy_freq_levels_cluster1 )
        {
          v12 = 1;
          v11 = 1;
        }
        else if ( v5 == &sysctl_legacy_freq_levels_cluster2 )
        {
          v12 = 1;
          v11 = 2;
        }
        else
        {
          v11 = 3;
          v12 = v5 == &sysctl_legacy_freq_levels_cluster3;
          if ( v5 != &sysctl_legacy_freq_levels_cluster3 )
            v11 = -1;
        }
        if ( !v9 )
          goto LABEL_35;
        if ( v12 )
        {
          v13 = 104 * v11;
          if ( ((416 * v11) | 0x18uLL) <= 0x680 )
          {
            v14 = &default_freq_config[v13];
            if ( !default_freq_config[v13 + 6] )
              goto LABEL_35;
            if ( v13 <= 334 )
            {
              if ( v9 > *((_QWORD *)v14 + 41) )
              {
                LODWORD(v8) = -22;
LABEL_43:
                mutex_unlock(&freq_reason_mutex);
                result = (unsigned int)v8;
                goto LABEL_23;
              }
              *((_QWORD *)v14 + 4) = v9;
              *((_QWORD *)v14 + 38) = v9;
LABEL_35:
              if ( (_DWORD)v8 )
              {
                v15 = 0;
                v16 = 104 * v11;
                v17 = &default_freq_config[v16];
                do
                {
                  if ( !v12 )
                    goto LABEL_44;
                  v18 = LODWORD(v26[v15 / 2]);
                  if ( (unsigned int)v18 > 0xA )
                    goto LABEL_44;
                  if ( v16 * 4 + 32 + 16 * v18 > 0x67F )
                    goto LABEL_45;
                  *(_QWORD *)&v17[4 * v18 + 8] = SHIDWORD(v26[v15 / 2]);
                  if ( v16 > 416 )
                    goto LABEL_45;
                  v15 += 2LL;
                  *v17 |= 1LL << v18;
                }
                while ( v15 < (unsigned int)v8 );
                LODWORD(v8) = 0;
              }
              goto LABEL_43;
            }
          }
        }
        else
        {
LABEL_44:
          __break(0x5512u);
        }
LABEL_45:
        __break(1u);
      }
      goto LABEL_22;
    }
  }
  else
  {
    v20 = &reason_dump;
    LODWORD(v21) = 1024;
    result = ((__int64 (__fastcall *)(__int64 *))sched_smart_freq_legacy_dump_handler)(&v19);
  }
LABEL_23:
  _ReadStatusReg(SP_EL0);
  return result;
}
