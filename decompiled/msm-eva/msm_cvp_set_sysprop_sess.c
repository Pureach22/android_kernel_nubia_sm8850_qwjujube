__int64 __fastcall msm_cvp_set_sysprop_sess(__int64 a1, int *a2, int a3)
{
  int v3; // w8
  __int64 result; // x0
  __int64 v6; // x3
  char v7; // w8
  unsigned __int64 StatusReg; // x8

  v3 = *a2;
  result = 4294967282LL;
  if ( *a2 > 6 )
  {
    if ( v3 <= 12 )
    {
      if ( v3 == 7 )
      {
        *(_DWORD *)(a1 + 14988) = a2[1];
        return 0;
      }
      else if ( v3 == 8 )
      {
        *(_DWORD *)(a1 + 14992) = a2[1];
        return 0;
      }
    }
    else
    {
      switch ( v3 )
      {
        case 13:
          v6 = (unsigned int)a2[1];
          result = 0;
          v7 = msm_cvp_debug;
          *(_DWORD *)(a1 + 15408) = v6;
          if ( (v7 & 4) != 0 && !msm_cvp_debug_out )
          {
            printk(&unk_90297, "info", a1, v6);
            return 0;
          }
          break;
        case 14:
          *(_DWORD *)(a1 + 14848) = a2[1];
          return 0;
        case 49:
          if ( (unsigned int)(4 * a3) < 0xFD )
          {
            *(_DWORD *)(a1 + (unsigned int)(4 * a3) + 14996) = a2[1];
            return 0;
          }
          else
          {
            if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
            {
              StatusReg = _ReadStatusReg(SP_EL0);
              printk(&unk_915F9, *(unsigned int *)(StatusReg + 1800), *(unsigned int *)(StatusReg + 1804), &unk_8E7CE);
            }
            *(_QWORD *)(a1 + 15236) = 0;
            *(_QWORD *)(a1 + 15244) = 0;
            *(_QWORD *)(a1 + 15220) = 0;
            *(_QWORD *)(a1 + 15228) = 0;
            *(_QWORD *)(a1 + 15204) = 0;
            *(_QWORD *)(a1 + 15212) = 0;
            *(_QWORD *)(a1 + 15188) = 0;
            *(_QWORD *)(a1 + 15196) = 0;
            *(_QWORD *)(a1 + 15172) = 0;
            *(_QWORD *)(a1 + 15180) = 0;
            *(_QWORD *)(a1 + 15156) = 0;
            *(_QWORD *)(a1 + 15164) = 0;
            *(_QWORD *)(a1 + 15140) = 0;
            *(_QWORD *)(a1 + 15148) = 0;
            *(_QWORD *)(a1 + 15124) = 0;
            *(_QWORD *)(a1 + 15132) = 0;
            *(_QWORD *)(a1 + 15108) = 0;
            *(_QWORD *)(a1 + 15116) = 0;
            *(_QWORD *)(a1 + 15092) = 0;
            *(_QWORD *)(a1 + 15100) = 0;
            *(_QWORD *)(a1 + 15076) = 0;
            *(_QWORD *)(a1 + 15084) = 0;
            *(_QWORD *)(a1 + 15060) = 0;
            *(_QWORD *)(a1 + 15068) = 0;
            *(_QWORD *)(a1 + 15044) = 0;
            *(_QWORD *)(a1 + 15052) = 0;
            *(_QWORD *)(a1 + 15028) = 0;
            *(_QWORD *)(a1 + 15036) = 0;
            *(_QWORD *)(a1 + 15012) = 0;
            *(_QWORD *)(a1 + 15020) = 0;
            *(_QWORD *)(a1 + 14996) = 0;
            *(_QWORD *)(a1 + 15004) = 0;
            return 4294967289LL;
          }
      }
    }
  }
  else if ( v3 <= 3 )
  {
    if ( v3 == 2 )
    {
      *(_DWORD *)(a1 + 14828) = a2[1];
      return 0;
    }
    else if ( v3 == 3 )
    {
      *(_DWORD *)(a1 + 14832) = a2[1];
      return 0;
    }
  }
  else
  {
    switch ( v3 )
    {
      case 4:
        *(_DWORD *)(a1 + 14836) = a2[1];
        return 0;
      case 5:
        *(_DWORD *)(a1 + 14840) = a2[1];
        return 0;
      case 6:
        *(_DWORD *)(a1 + 14844) = a2[1];
        return 0;
    }
  }
  return result;
}
