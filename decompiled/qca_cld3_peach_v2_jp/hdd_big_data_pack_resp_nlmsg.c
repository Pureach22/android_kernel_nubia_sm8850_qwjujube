__int64 __fastcall hdd_big_data_pack_resp_nlmsg(__int64 a1, __int64 a2)
{
  __int64 *v4; // x21
  double v5; // d0
  double v6; // d1
  double v7; // d2
  double v8; // d3
  double v9; // d4
  double v10; // d5
  double v11; // d6
  double v12; // d7
  const char *v13; // x2
  __int64 result; // x0
  int roam_states; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v16; // [xsp+8h] [xbp-8h]

  v16 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = *(__int64 **)(*(_QWORD *)a2 + 24LL);
  roam_states = *(_DWORD *)(a2 + 4396);
  if ( (unsigned int)nla_put(a1, 44, 4, &roam_states) )
  {
    v13 = "%s: latest tx rate put fail";
  }
  else
  {
    if ( wlan_reg_is_5ghz_ch_freq(*(_DWORD *)(a2 + 1372)) )
    {
      roam_states = *(_DWORD *)(a2 + 4388);
      if ( (unsigned int)nla_put(a1, 30, 4, &roam_states) )
      {
        v13 = "%s: 5G ofdm power put fail";
        goto LABEL_3;
      }
    }
    else if ( wlan_reg_is_24ghz_ch_freq(*(_DWORD *)(a2 + 1372)) )
    {
      roam_states = *(_DWORD *)(a2 + 4388);
      if ( (unsigned int)nla_put(a1, 28, 4, &roam_states) )
      {
        v13 = "%s: 2.4G ofdm power put fail";
        goto LABEL_3;
      }
      roam_states = *(_DWORD *)(a2 + 4384);
      if ( (unsigned int)nla_put(a1, 27, 4, &roam_states) )
      {
        v13 = "%s: target power dsss put fail";
        goto LABEL_3;
      }
    }
    roam_states = *(_DWORD *)(a2 + 4392);
    if ( (unsigned int)nla_put(a1, 45, 4, &roam_states) )
    {
      v13 = "%s: last rix rate put fail";
    }
    else
    {
      roam_states = *(_DWORD *)(a2 + 4372);
      if ( (unsigned int)nla_put(a1, 46, 4, &roam_states) )
      {
        v13 = "%s: tsf out of sync put fail";
      }
      else
      {
        roam_states = *(_DWORD *)(a2 + 4376);
        if ( (unsigned int)nla_put(a1, 35, 4, &roam_states) )
        {
          v13 = "%s: ani level put fail";
        }
        else
        {
          roam_states = *(_DWORD *)(a2 + 4380);
          if ( (unsigned int)nla_put(a1, 34, 4, &roam_states) )
          {
            v13 = "%s: last data tx power put fail";
          }
          else
          {
            roam_states = wlan_cm_get_roam_states(*v4, *(unsigned __int8 *)(a2 + 8), 0);
            if ( (unsigned int)nla_put(a1, 47, 4, &roam_states) )
            {
              v13 = "%s: roam trigger reason put fail";
            }
            else
            {
              roam_states = wlan_cm_get_roam_states(*v4, *(unsigned __int8 *)(a2 + 8), 2);
              if ( (unsigned int)nla_put(a1, 48, 4, &roam_states) )
              {
                v13 = "%s: roam fail reason put fail";
              }
              else
              {
                roam_states = wlan_cm_get_roam_states(*v4, *(unsigned __int8 *)(a2 + 8), 1);
                result = nla_put(a1, 49, 4, &roam_states);
                if ( !(_DWORD)result )
                  goto LABEL_4;
                v13 = "%s: roam invoke fail reason put fail";
              }
            }
          }
        }
      }
    }
  }
LABEL_3:
  qdf_trace_msg(0x33u, 2u, v13, v5, v6, v7, v8, v9, v10, v11, v12, "hdd_big_data_pack_resp_nlmsg");
  result = 4294967274LL;
LABEL_4:
  _ReadStatusReg(SP_EL0);
  return result;
}
