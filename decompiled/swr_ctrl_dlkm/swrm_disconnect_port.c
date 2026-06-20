__int64 __fastcall swrm_disconnect_port(__int64 a1, unsigned __int8 *a2)
{
  _DWORD *v3; // x20
  __int64 v5; // x26
  unsigned __int8 *v6; // x27
  __int64 v7; // x8
  __int64 *v8; // x9
  int v9; // w10
  int v10; // w9
  int v11; // w8
  int v13; // w11
  __int64 result; // x0
  unsigned int v15; // w9
  char v17; // w9
  unsigned __int64 v22; // x9
  unsigned __int8 v23; // [xsp+Ch] [xbp-14h]
  _BYTE v24[4]; // [xsp+10h] [xbp-10h] BYREF
  _BYTE v25[4]; // [xsp+14h] [xbp-Ch] BYREF
  __int64 v26; // [xsp+18h] [xbp-8h]

  v26 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( !a1 || (v3 = *(_DWORD **)(a1 + 152), v25[0] = 0, v24[0] = 0, !v3) )
  {
    if ( (unsigned int)__ratelimit(&swrm_disconnect_port__rs, "swrm_disconnect_port") )
      dev_err(a1, "%s: Invalid handle to swr controller\n", "swrm_disconnect_port");
    goto LABEL_41;
  }
  if ( !a2 )
  {
    if ( (unsigned int)__ratelimit(&swrm_disconnect_port__rs_157, "swrm_disconnect_port") )
      dev_err(a1, "%s: portinfo is NULL\n", "swrm_disconnect_port");
LABEL_41:
    result = 4294967274LL;
    goto LABEL_42;
  }
  mutex_lock(v3 + 2196);
  if ( a2[2] )
  {
    v5 = 0;
    v6 = a2 + 3;
    v23 = 0;
    while ( 1 )
    {
      if ( v5 == 14 )
LABEL_52:
        __break(0x5512u);
      if ( (unsigned int)swrm_get_master_port(v3, v25, v24, a2[v5 + 102]) )
      {
        if ( (unsigned int)__ratelimit(&swrm_disconnect_port__rs_159, "swrm_disconnect_port") )
          dev_err(a1, "%s: mstr portid for slv port %d not found\n", "swrm_disconnect_port", v6[v5]);
        swr_port_response(a1, *a2);
        mutex_unlock(v3 + 2196);
        goto LABEL_41;
      }
      if ( v25[0] > 0x9AuLL )
        goto LABEL_52;
      v7 = (__int64)&v3[10 * v25[0] + 2288];
      v8 = *(__int64 **)v7;
      if ( *(_QWORD *)v7 == v7 )
        goto LABEL_6;
      while ( *((unsigned __int8 *)v8 - 6) != v6[v5] || *((unsigned __int8 *)v8 - 8) != a2[1] )
      {
        v8 = (__int64 *)*v8;
        if ( v8 == (__int64 *)v7 )
          goto LABEL_6;
      }
      if ( v8 == (__int64 *)&unk_8 )
      {
LABEL_6:
        if ( (unsigned int)__ratelimit(&swrm_disconnect_port__rs_160, "swrm_disconnect_port") )
          dev_err(a1, "%s:port not enabled : port %d\n", "swrm_disconnect_port", v6[v5]);
        goto LABEL_8;
      }
      *((_BYTE *)v8 + 24) &= ~a2[v5 + 88];
      v9 = *(unsigned __int8 *)(v7 + 18) & (v24[0] ^ 0xFF);
      *(_BYTE *)(v7 + 18) &= ~v24[0];
      if ( v3[3926] && v3[2265] && !v9 )
      {
        *(_DWORD *)(v7 + 32) = 0;
        v10 = v3[2306]
            + v3[2296]
            + v3[2316]
            + v3[2326]
            + v3[2336]
            + v3[2346]
            + v3[2356]
            + v3[2366]
            + v3[2376]
            + v3[2386]
            + v3[2396]
            + v3[2406]
            + v3[2416];
        v11 = v3[2283];
        if ( v10 )
        {
          if ( v11 != 12288000 && v11 != 11289600 )
          {
            _ZF = v11 == 9600000;
            v11 = v3[2306]
                + v3[2296]
                + v3[2316]
                + v3[2326]
                + v3[2336]
                + v3[2346]
                + v3[2356]
                + v3[2366]
                + v3[2376]
                + v3[2386]
                + v3[2396]
                + v3[2406]
                + v3[2416];
            if ( _ZF )
            {
LABEL_32:
              v11 = 600000;
              if ( v10 >= 600001 )
              {
                if ( (unsigned int)v10 <= 0x493E00 )
                  v11 = 4800000;
                else
                  v11 = 9600000;
              }
            }
          }
        }
      }
      else
      {
        v13 = *(_DWORD *)(v7 + 32);
        if ( !v13 || !v9 )
          goto LABEL_38;
        *(_DWORD *)(v7 + 32) = v13 - *((_DWORD *)v8 + 7);
        v10 = v3[2306]
            + v3[2296]
            + v3[2316]
            + v3[2326]
            + v3[2336]
            + v3[2346]
            + v3[2356]
            + v3[2366]
            + v3[2376]
            + v3[2386]
            + v3[2396]
            + v3[2406]
            + v3[2416];
        v11 = v3[2283];
        if ( v10 && v11 != 12288000 && v11 != 11289600 )
        {
          if ( v11 == 9600000 )
            goto LABEL_32;
          v11 = v3[2306]
              + v3[2296]
              + v3[2316]
              + v3[2326]
              + v3[2336]
              + v3[2346]
              + v3[2356]
              + v3[2366]
              + v3[2376]
              + v3[2386]
              + v3[2396]
              + v3[2406]
              + v3[2416];
        }
      }
      v3[2284] = v11;
LABEL_38:
      ++v23;
LABEL_8:
      if ( ++v5 >= (unsigned __int64)a2[2] )
        goto LABEL_46;
    }
  }
  v23 = 0;
LABEL_46:
  v15 = *(unsigned __int8 *)(a1 + 8409);
  _CF = v15 >= v23;
  v17 = v15 - v23;
  if ( !_CF )
    v17 = 0;
  *(_BYTE *)(a1 + 8409) = v17;
  _X8 = (unsigned __int64 *)(v3 + 3832);
  __asm { PRFM            #0x11, [X8] }
  do
    v22 = __ldxr(_X8);
  while ( __stxr(v22 | 2, _X8) );
  swr_port_response(a1, *a2);
  mutex_unlock(v3 + 2196);
  result = 0;
LABEL_42:
  _ReadStatusReg(SP_EL0);
  return result;
}
