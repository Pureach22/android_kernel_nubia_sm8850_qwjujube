__int64 __fastcall cdsprm_cxlimit_npu_activity_notify(int a1)
{
  int v2; // w8
  int v3; // w9
  unsigned int v4; // w21
  __int64 v5; // x8
  __int64 v6; // x0
  __int64 v8; // [xsp+8h] [xbp-18h] BYREF
  int v9; // [xsp+10h] [xbp-10h]
  __int64 v10; // [xsp+18h] [xbp-8h]

  v10 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( byte_A3D8 == 1 )
  {
    v9 = 0;
    v8 = 0;
    mutex_lock(&unk_A3A8);
    v2 = dword_A430;
    if ( a1 )
    {
      v3 = 1;
    }
    else
    {
      if ( !dword_A430 )
      {
        if ( dword_A3DC )
        {
          v4 = -22;
          v5 = qword_A350;
          dword_A3DC = 0;
          if ( !qword_A350 || !gcdsprm[0] )
            goto LABEL_22;
LABEL_15:
          v6 = *(_QWORD *)(v5 + 968);
          LODWORD(v8) = 6;
          HIDWORD(v8) = a1;
          v9 = 12;
          v4 = rpmsg_send(v6, &v8, 12);
          if ( !dword_A3DC || !v4 )
          {
            if ( !dword_A3DC || v4 )
              goto LABEL_22;
            mutex_unlock(&unk_A3A8);
            wait_for_completion(&dword_A3F0);
            mutex_lock(&unk_A3A8);
          }
          --dword_A3E4;
LABEL_22:
          mutex_unlock(&unk_A3A8);
          goto LABEL_23;
        }
LABEL_21:
        v4 = 0;
        goto LABEL_22;
      }
      v3 = -1;
    }
    dword_A430 += v3;
    if ( (v2 + v3 != 0) != (dword_A3DC != 0) )
    {
      v4 = -22;
      v5 = qword_A350;
      dword_A3DC = a1;
      if ( !qword_A350 || !gcdsprm[0] )
        goto LABEL_22;
      if ( a1 )
        ++dword_A3E4;
      goto LABEL_15;
    }
    goto LABEL_21;
  }
  v4 = -22;
LABEL_23:
  _ReadStatusReg(SP_EL0);
  return v4;
}
