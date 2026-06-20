__int64 __fastcall rmnet_shs_genl_batch_move_flow(__int64 a1, __int64 a2)
{
  __int64 v3; // x1
  unsigned int v4; // w8
  __int64 v5; // x20
  unsigned __int64 v6; // x22
  int v7; // w21
  unsigned int v8; // w1
  unsigned int v9; // w0
  _BOOL4 v10; // w0
  __int64 result; // x0
  int v12; // w1
  _WORD s[302]; // [xsp+Ch] [xbp-264h] BYREF
  __int64 v14; // [xsp+268h] [xbp-8h]

  v14 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( a2 )
  {
    memset(s, 0, sizeof(s));
    v3 = *(_QWORD *)(*(_QWORD *)(a2 + 32) + 72LL);
    if ( !v3 )
      goto LABEL_20;
    if ( (int)nla_memcpy(s, v3, 604) < 1 )
      goto LABEL_20;
    v4 = s[0];
    if ( s[0] > 0x31u )
      goto LABEL_20;
    if ( !s[0] )
      goto LABEL_23;
    v5 = 0;
    v6 = 0;
    v7 = 0;
    do
    {
      if ( v5 == 300 )
        goto LABEL_25;
      if ( (unsigned __int64)(v5 * 2 - 591) < 0xFFFFFFFFFFFFFDA3LL )
        goto LABEL_24;
      v8 = (unsigned __int16)s[v5 + 7];
      if ( v8 > 7 )
        goto LABEL_7;
      if ( (unsigned __int64)(v5 * 2 - 592) < 0xFFFFFFFFFFFFFDA4LL )
        goto LABEL_24;
      v9 = (unsigned __int16)s[v5 + 6];
      if ( v9 >= 8 )
      {
LABEL_7:
        ++v7;
        ++qword_1A3A0;
      }
      else
      {
        if ( (unsigned __int64)(v5 * 2 - 596) < 0xFFFFFFFFFFFFFDA4LL )
        {
LABEL_24:
          __break(1u);
LABEL_25:
          __break(0x5512u);
        }
        v10 = rmnet_shs_wq_try_to_move_flow(v9, v8, *(_DWORD *)&s[v5 + 2], *(_DWORD *)&s[v5 + 4]);
        v4 = s[0];
        if ( !v10 )
          ++v7;
      }
      ++v6;
      v5 += 6;
    }
    while ( v6 < v4 );
    if ( v7 )
LABEL_20:
      v12 = 501;
    else
LABEL_23:
      v12 = 500;
    rmnet_shs_genl_send_int_to_userspace(a2, v12);
    result = 0;
  }
  else
  {
    result = 0xFFFFFFFFLL;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
