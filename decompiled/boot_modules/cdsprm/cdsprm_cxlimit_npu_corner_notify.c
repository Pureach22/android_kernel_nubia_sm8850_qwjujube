__int64 __fastcall cdsprm_cxlimit_npu_corner_notify(__int64 result)
{
  unsigned int v1; // w20
  unsigned int v2; // w19
  __int64 v3; // x0
  int v4; // w0
  __int64 v5; // [xsp+8h] [xbp-18h] BYREF
  int v6; // [xsp+10h] [xbp-10h]
  __int64 v7; // [xsp+18h] [xbp-8h]

  v7 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( (byte_A48B & 1) == 0 && byte_A3D8 == 1 )
  {
    v1 = result;
    v6 = 0;
    v5 = 0;
    mutex_lock(&unk_A3A8);
    v2 = dword_A434;
    dword_A434 = v1;
    if ( !qword_A350 || !gcdsprm[0] )
      goto LABEL_14;
    if ( v1 - 1 >= v2 )
      ++dword_A3E8;
    v3 = *(_QWORD *)(qword_A350 + 968);
    LODWORD(v5) = 8;
    HIDWORD(v5) = v1;
    v6 = 12;
    v4 = rpmsg_send(v3, &v5, 12);
    if ( dword_A434 - 1 < v2 || !v4 )
    {
      if ( dword_A434 - 1 < v2 || v4 )
        goto LABEL_14;
      mutex_unlock(&unk_A3A8);
      wait_for_completion(&dword_A410);
      mutex_lock(&unk_A3A8);
      if ( dword_A438 )
      {
        v1 = dword_A438;
        dword_A434 = dword_A438;
      }
    }
    --dword_A3E8;
LABEL_14:
    mutex_unlock(&unk_A3A8);
    result = v1;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
