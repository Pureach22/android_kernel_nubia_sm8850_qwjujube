__int64 __fastcall spss_stop(__int64 a1)
{
  __int64 v2; // x21
  __int64 v3; // x20
  const char *v4; // x3
  char s[8]; // [xsp+8h] [xbp-48h] BYREF
  __int64 v7; // [xsp+10h] [xbp-40h]
  __int64 v8; // [xsp+18h] [xbp-38h]
  __int64 v9; // [xsp+20h] [xbp-30h]
  __int64 v10; // [xsp+28h] [xbp-28h]
  __int64 v11; // [xsp+30h] [xbp-20h]
  __int64 v12; // [xsp+38h] [xbp-18h]
  __int64 v13; // [xsp+40h] [xbp-10h]
  __int64 v14; // [xsp+48h] [xbp-8h]

  v14 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = *(_QWORD *)(a1 + 40);
  if ( (unsigned int)qcom_scm_pas_shutdown(*(unsigned int *)(v2 + 56)) )
    panic("Panicking, remoteproc %s failed to shutdown.\n", *(const char **)(a1 + 24));
  **(_DWORD **)(v2 + 392) = -1;
  v3 = *(_QWORD *)(v2 + 144);
  if ( v3 )
  {
    v4 = *(const char **)(v2 + 136);
    v12 = 0;
    v13 = 0;
    v10 = 0;
    v11 = 0;
    v8 = 0;
    v9 = 0;
    *(_QWORD *)s = 0;
    v7 = 0;
    snprintf(s, 0x40u, "{class: image, res: load_state, name: %s, val: %s}", v4, "off");
    qmp_send(v3, s, 64);
  }
  *(_DWORD *)(a1 + 972) = 0;
  _ReadStatusReg(SP_EL0);
  *(_DWORD *)(v2 + 64) = 0;
  return 0;
}
