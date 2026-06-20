size_t __fastcall dp_debug_write_edid_modes_mst(__int64 a1, unsigned __int64 a2, size_t a3, _QWORD *a4)
{
  __int64 v4; // x27
  const char *v8; // x24
  unsigned __int64 StatusReg; // x20
  __int64 v10; // x0
  bool v11; // zf
  __int64 v12; // x8
  int v13; // w11
  int v14; // w10
  int v15; // w9
  int v16; // w12
  __int64 v17; // x21
  __int64 v18; // x0
  __int64 ipc_log_context; // x0
  int v21; // [xsp+14h] [xbp-22Ch] BYREF
  __int64 v22; // [xsp+18h] [xbp-228h] BYREF
  __int64 v23; // [xsp+20h] [xbp-220h] BYREF
  __int64 v24; // [xsp+28h] [xbp-218h] BYREF
  char s[512]; // [xsp+30h] [xbp-210h] BYREF
  __int64 v26; // [xsp+230h] [xbp-10h]

  v26 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = *(_QWORD *)(a1 + 32);
  v23 = 0;
  v24 = 0;
  v22 = 0;
  v21 = 0;
  if ( v4 )
  {
    memset(s, 0, sizeof(s));
    mutex_lock(v4 + 376);
    if ( *a4 )
    {
      a3 = 0;
    }
    else
    {
      if ( a3 >= 0x1FF )
        a3 = 511;
      _check_object_size(s, a3, 0);
      if ( !inline_copy_from_user((__int64)s, a2, a3) )
      {
        s[a3] = 0;
        if ( sscanf(
               s,
               "%d %d %d %d %d %d%n",
               &v21,
               (char *)&v22 + 4,
               (char *)&v24 + 4,
               &v24,
               (char *)&v23 + 4,
               &v23,
               &v22) == 6 )
        {
          v8 = s;
          StatusReg = _ReadStatusReg(SP_EL0);
          do
          {
            v10 = drm_mode_object_find(***(_QWORD ***)(v4 + 144), 0, HIDWORD(v22), 3233857728LL);
            if ( v10 )
              v11 = v10 == 64;
            else
              v11 = 1;
            if ( v11 )
            {
              ipc_log_context = get_ipc_log_context(v10);
              ipc_log_string(
                ipc_log_context,
                "[e][%-4d]invalid connector id %d\n",
                *(_DWORD *)(StatusReg + 1800),
                HIDWORD(v22));
              printk(&unk_226722, "dp_debug_write_edid_modes_mst");
            }
            else
            {
              v12 = *(_QWORD *)(v10 + 2704);
              if ( v12 && *(_QWORD *)(v10 + 2712) )
              {
                v13 = v24;
                v14 = v21;
                *(_DWORD *)(v12 + 984) = HIDWORD(v24);
                v15 = v23;
                v16 = HIDWORD(v23);
                *(_DWORD *)(v12 + 988) = v13;
                *(_BYTE *)(v12 + 981) = v14 != 0;
                *(_DWORD *)(v12 + 992) = v16;
                *(_DWORD *)(v12 + 996) = v15;
              }
              else
              {
                v17 = v10;
                v18 = get_ipc_log_context(v10);
                ipc_log_string(
                  v18,
                  "[e][%-4d]connector id %d is not mst\n",
                  *(_DWORD *)(StatusReg + 1800),
                  HIDWORD(v22));
                printk(&unk_22D431, "dp_debug_write_edid_modes_mst");
                v10 = v17;
              }
              drm_mode_object_put(v10);
            }
            v8 += (int)v22;
          }
          while ( sscanf(
                    v8,
                    "%d %d %d %d %d %d%n",
                    &v21,
                    (char *)&v22 + 4,
                    (char *)&v24 + 4,
                    &v24,
                    (char *)&v23 + 4,
                    &v23,
                    &v22) == 6 );
        }
      }
    }
    mutex_unlock(v4 + 376);
  }
  else
  {
    a3 = -19;
  }
  _ReadStatusReg(SP_EL0);
  return a3;
}
