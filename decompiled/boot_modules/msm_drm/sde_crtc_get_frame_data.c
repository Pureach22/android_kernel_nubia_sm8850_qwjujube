void *__fastcall sde_crtc_get_frame_data(__int64 *a1)
{
  void *result; // x0
  __int64 v3; // x8
  __int64 v4; // x8
  _BYTE *v5; // x10
  __int64 v6; // x9
  __int64 *v7; // x20
  unsigned __int64 v8; // x8
  _BYTE *v9; // x21
  unsigned __int64 v10; // x23
  __int64 v11; // x8
  __int64 v12; // x8
  int v13; // w9
  _DWORD v14[3]; // [xsp+Ch] [xbp-344h] BYREF
  _BYTE s[816]; // [xsp+18h] [xbp-338h] BYREF
  __int64 v16; // [xsp+348h] [xbp-8h]

  v16 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  result = memset(s, 0, sizeof(s));
  if ( a1 && a1[251] )
  {
    if ( *((_DWORD *)a1 + 1971) )
    {
      v3 = *((unsigned int *)a1 + 1970);
      if ( (unsigned int)v3 >= 3 )
        goto LABEL_18;
      v4 = *(_QWORD *)(a1[v3 + 986] + 16);
      v5 = (_BYTE *)(*(_QWORD *)(v4 + 432) + *(unsigned int *)(v4 + 664));
    }
    else
    {
      v5 = s;
    }
    *((_QWORD *)v5 + 1) = a1[552];
    *(_DWORD *)v5 = *((_DWORD *)a1 + 1112);
    v6 = *a1;
    v7 = *(__int64 **)(*a1 + 840);
    if ( v7 != (__int64 *)(*a1 + 840) )
    {
      v8 = 0;
      v9 = v5 + 16;
      do
      {
        if ( ((*((_DWORD *)a1 + 1892) >> *((_DWORD *)v7 + 437)) & 1) != 0 && (int)v8 <= 19 )
        {
          if ( v8 > 0x14 )
            goto LABEL_18;
          v10 = v8 + 1;
          result = (void *)sde_plane_get_frame_data(v7 - 1, &v9[40 * v8]);
          v6 = *a1;
          v8 = v10;
        }
        v7 = (__int64 *)*v7;
      }
      while ( v7 != (__int64 *)(v6 + 840) );
    }
    if ( *((_DWORD *)a1 + 1971) )
    {
      v11 = *((unsigned int *)a1 + 1970);
      v14[2] = 0;
      if ( (unsigned int)v11 < 3 )
      {
        v12 = a1[v11 + 986];
        v13 = *(_DWORD *)(*(_QWORD *)(v12 + 16) + 664LL);
        v14[0] = *(_DWORD *)v12;
        v14[1] = v13;
        result = (void *)sde_crtc_event_notify(a1, 2147483660LL, v14, 12);
        *((_DWORD *)a1 + 1970) = (unsigned int)(*((_DWORD *)a1 + 1970) + 1) % *((_DWORD *)a1 + 1971);
        goto LABEL_17;
      }
LABEL_18:
      __break(0x5512u);
    }
  }
LABEL_17:
  _ReadStatusReg(SP_EL0);
  return result;
}
