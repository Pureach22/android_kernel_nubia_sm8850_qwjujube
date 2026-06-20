void __fastcall target_process_bang_radar_cmd(
        __int64 a1,
        _DWORD *a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        __int64 a7,
        __int64 a8,
        __int64 a9,
        __int64 a10,
        __int128 a11,
        int a12)
{
  __int64 *v14; // x8
  __int64 v15; // x20
  unsigned int v16; // w8

  _ReadStatusReg(SP_EL0);
  memset((char *)&a11 + 4, 0, 0x194u);
  HIDWORD(a9) = 0;
  if ( a1 )
  {
    v14 = *(__int64 **)(a1 + 1232);
    if ( v14 )
    {
      v15 = *v14;
      if ( *v14 )
      {
        v16 = a2[1];
        LODWORD(a10) = *a2;
        HIDWORD(a10) = 43;
        LODWORD(a11) = v16;
        if ( !v16 || (DWORD2(a11) = a2[2], v16 < 3) || (a12 = a2[4], v16 == 3) )
        {
          if ( (unsigned int)wmi_convert_pdev_id_host_to_target(v15, *(unsigned __int8 *)(a1 + 40), (_DWORD *)&a9 + 1) )
            JUMPOUT(0x636C30);
          JUMPOUT(0x636C8C);
        }
        JUMPOUT(0x636CD4);
      }
    }
    JUMPOUT(0x636C34);
  }
  JUMPOUT(0x636C40);
}
