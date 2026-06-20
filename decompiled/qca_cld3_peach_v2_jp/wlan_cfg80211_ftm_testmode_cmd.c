__int64 __fastcall wlan_cfg80211_ftm_testmode_cmd(__int64 a1, __int64 a2, unsigned int a3)
{
  __int64 comp_private_obj; // x0
  __int64 result; // x0
  _BOOL4 v8; // w8
  __int64 v9; // [xsp+8h] [xbp-28h] BYREF
  __int64 v10; // [xsp+10h] [xbp-20h]
  unsigned __int16 *v11; // [xsp+18h] [xbp-18h]
  __int64 v12; // [xsp+20h] [xbp-10h]
  __int64 v13; // [xsp+28h] [xbp-8h]

  v13 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v11 = nullptr;
  v12 = 0;
  v9 = 0;
  v10 = 0;
  comp_private_obj = wlan_objmgr_pdev_get_comp_private_obj(a1, 0x17u);
  if ( !comp_private_obj )
    goto LABEL_8;
  *(_DWORD *)(comp_private_obj + 40) = 2;
  result = _nla_parse(&v9, 2, a2, a3, &wlan_cfg80211_ftm_policy, 31, 0);
  if ( !(_DWORD)result )
  {
    if ( v10 )
    {
      if ( *(_DWORD *)(v10 + 4) )
      {
        result = 4294967294LL;
        goto LABEL_9;
      }
      if ( v11 && (unsigned int)*v11 - 4 <= 0x800 )
      {
        v8 = ucfg_wlan_ftm_testmode_cmd(a1) != 0;
        result = qdf_status_to_os_return(8 * v8);
        goto LABEL_9;
      }
    }
LABEL_8:
    result = 4294967274LL;
  }
LABEL_9:
  _ReadStatusReg(SP_EL0);
  return result;
}
