__int64 __fastcall msm_hdcp_notify_topology(__int64 a1)
{
  __int64 v1; // x20
  __int64 v2; // x0
  __int64 result; // x0
  void *v4; // x0
  char v5[8]; // [xsp+8h] [xbp-48h] BYREF
  __int64 v6; // [xsp+10h] [xbp-40h]
  char s[8]; // [xsp+18h] [xbp-38h] BYREF
  __int64 v8; // [xsp+20h] [xbp-30h]
  _QWORD v9[5]; // [xsp+28h] [xbp-28h] BYREF

  v9[4] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  *(_QWORD *)s = 0;
  v8 = 0;
  *(_QWORD *)v5 = 0;
  v6 = 0;
  if ( !a1 )
  {
    v4 = &unk_241618;
LABEL_7:
    result = printk(v4, "msm_hdcp_notify_topology");
    goto LABEL_4;
  }
  v1 = *(_QWORD *)(a1 + 152);
  if ( !v1 )
  {
    v4 = &unk_2339E9;
    goto LABEL_7;
  }
  snprintf(s, 0x10u, "%d", 0);
  snprintf(v5, 0x10u, "%d", 0);
  v2 = *(_QWORD *)(v1 + 160);
  v9[0] = "HDCP_MGR_EVENT=MSG_READY";
  v9[1] = s;
  v9[2] = v5;
  v9[3] = 0;
  result = kobject_uevent_env(v2, 2, v9);
LABEL_4:
  _ReadStatusReg(SP_EL0);
  return result;
}
