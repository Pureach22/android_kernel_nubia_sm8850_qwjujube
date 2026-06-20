__int64 __fastcall dsi_display_get_active_displays(__int64 a1, _QWORD *a2, int a3)
{
  __int64 v3; // x10
  __int64 v4; // x8
  __int64 v6; // x10

  if ( a2 && a3 )
  {
    if ( qword_F120 )
    {
      v3 = *(_QWORD *)(qword_F120 + 8);
      LODWORD(v4) = 0;
      if ( v3 )
      {
        if ( v3 == a1 && (*(_QWORD *)(qword_F120 + 272) || (v4 = *(_QWORD *)(qword_F120 + 1584)) != 0) )
        {
          LODWORD(v4) = 1;
          *a2 = qword_F120;
        }
      }
    }
    else
    {
      LODWORD(v4) = 0;
    }
    if ( qword_F348 )
    {
      v6 = *(_QWORD *)(qword_F348 + 8);
      if ( v6 )
      {
        if ( v6 == a1 && (*(_QWORD *)(qword_F348 + 272) || *(_QWORD *)(qword_F348 + 1584)) )
        {
          a2[(unsigned int)v4] = qword_F348;
          LODWORD(v4) = v4 + 1;
        }
      }
    }
    return (unsigned int)v4;
  }
  else
  {
    drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: invalid params\n");
    return 0;
  }
}
