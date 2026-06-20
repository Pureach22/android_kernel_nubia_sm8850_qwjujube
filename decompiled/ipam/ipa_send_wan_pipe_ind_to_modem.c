__int64 __fastcall ipa_send_wan_pipe_ind_to_modem(__int64 result)
{
  char v1; // w19
  unsigned int v2; // w20
  unsigned int v3; // w8
  _QWORD *v4; // x21
  _QWORD *v5; // x19
  _QWORD s[65]; // [xsp+8h] [xbp-208h] BYREF

  s[64] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( (_DWORD)result )
  {
    v1 = result;
    result = (__int64)memset(s, 0, 0x200u);
    v2 = 0;
    if ( (v1 & 2) != 0 )
    {
      v2 = 1;
      LOBYTE(s[0]) = 1;
      *(_QWORD *)((char *)s + 4) = 0x400000001LL;
      LOBYTE(s[63]) = 1;
      v3 = *(_DWORD *)(rmnet_ipa3_ctx + 1084);
      HIDWORD(s[63]) = 1;
      HIDWORD(s[1]) = 3;
      s[2] = v3 | 0x200000000LL;
    }
    if ( (v1 & 4) != 0 )
    {
      LOBYTE(s[0]) = 1;
      v4 = &s[2 * v2 + 1];
      LOBYTE(s[63]) = 1;
      v5 = &s[2 * v2 + 3];
      *((_DWORD *)v4 + 2) = ipa_get_ep_mapping(105);
      *((_DWORD *)v4 + 3) = 2;
      *v4 = 0xB00000004LL;
      HIDWORD(s[0]) = v2 | 2;
      HIDWORD(s[63]) = v2 | 2;
      *((_DWORD *)v5 + 2) = ipa_get_ep_mapping(104);
      *((_DWORD *)v5 + 3) = 2;
      *v5 = 0xA00000004LL;
    }
    else if ( (v1 & 2) == 0 )
    {
      goto LABEL_9;
    }
    result = ipa3_qmi_send_endp_desc_indication((__int64)s);
  }
LABEL_9:
  _ReadStatusReg(SP_EL0);
  return result;
}
