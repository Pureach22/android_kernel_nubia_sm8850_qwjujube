__int64 __fastcall dsi_display_find_mode(__int64 a1, __int64 a2, _DWORD *a3, _QWORD *a4)
{
  __int64 result; // x0
  __int64 v9; // x24
  unsigned __int64 v10; // x23
  __int64 v11; // x8
  __int64 v12; // x26
  __int64 v13; // x25
  int v14; // w24
  __int64 v15; // x27
  __int64 v16; // x28
  int v17; // w8
  int v18; // w8
  __int64 v19[2]; // [xsp+0h] [xbp-10h] BYREF

  result = 4294967274LL;
  v19[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( a1 )
  {
    if ( a4 )
    {
      v19[0] = 0;
      *a4 = 0;
      mutex_lock(a1 + 72);
      v9 = *(unsigned int *)(*(_QWORD *)(a1 + 264) + 1436LL);
      mutex_unlock(a1 + 72);
      if ( *(_QWORD *)(a1 + 824) || (result = dsi_display_get_modes(a1, v19), !(_DWORD)result) )
      {
        v10 = _kvmalloc_node_noprof(3456, 0, 3520, 0xFFFFFFFFLL);
        if ( v10 < 0x11 )
        {
          result = 4294967284LL;
          goto LABEL_27;
        }
        mutex_lock(a1 + 72);
        if ( (_DWORD)v9 )
        {
          v11 = 3 * v9;
          v12 = *(_QWORD *)(a1 + 264);
          v13 = 0;
          v14 = 3;
          v15 = v11 << 6;
          do
          {
            v16 = *(_QWORD *)(a1 + 824);
            if ( *(_BYTE *)(v12 + 1400) )
              v14 = 1;
            v19[0] = v16 + v13;
            if ( a3 )
            {
              if ( *a3 )
              {
                *(_QWORD *)(a2 + 184) = v10;
                v14 |= 4u;
                *(_BYTE *)(v10 + 3400) = *a3 == 1;
              }
              v17 = a3[1];
              if ( v17 == 1 )
              {
                v18 = 3;
              }
              else
              {
                if ( v17 != 2 )
                  goto LABEL_20;
                v18 = 7;
              }
              v14 |= 8u;
              *(_DWORD *)(a2 + 164) = v18;
            }
LABEL_20:
            if ( (dsi_display_mode_match(a2, v16 + v13, v14) & 1) != 0 )
            {
              *a4 = v16 + v13;
              break;
            }
            v13 += 192;
          }
          while ( v15 != v13 );
        }
        *(_QWORD *)(a2 + 184) = 0;
        mutex_unlock(a1 + 72);
        kvfree(v10);
        if ( *a4 )
        {
          result = 0;
        }
        else
        {
          drm_dev_printk(
            0,
            &unk_248D72,
            "*ERROR* [msm-dsi-error]: [%s] failed to find mode for v_active %u h_active %u fps %u pclk %u\n",
            *(const char **)(a1 + 32),
            *(_DWORD *)(a2 + 24),
            *(_DWORD *)a2,
            *(_DWORD *)(a2 + 44),
            *(_DWORD *)(a2 + 152));
          result = 4294967294LL;
        }
      }
    }
  }
LABEL_27:
  _ReadStatusReg(SP_EL0);
  return result;
}
