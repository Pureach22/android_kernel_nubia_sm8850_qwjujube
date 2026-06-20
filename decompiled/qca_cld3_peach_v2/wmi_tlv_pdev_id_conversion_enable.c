__int64 __fastcall wmi_tlv_pdev_id_conversion_enable(__int64 result, _DWORD *a2, unsigned __int8 a3)
{
  char v3; // w8
  __int64 v4; // x8
  int v5; // w10
  __int64 v6; // x10

  v3 = 0;
  if ( a2 && a3 <= 3u )
  {
    if ( a3 )
    {
      **(_DWORD **)(result + 856) = *a2;
      **(_DWORD **)(result + 864) = -1;
      **(_DWORD **)(result + 872) = *a2 - 1;
      **(_DWORD **)(result + 880) = -1;
      if ( a3 != 1 )
      {
        *(_DWORD *)(*(_QWORD *)(result + 856) + 4LL) = a2[1];
        *(_DWORD *)(*(_QWORD *)(result + 864) + 4LL) = -1;
        *(_DWORD *)(*(_QWORD *)(result + 872) + 4LL) = a2[1] - 1;
        *(_DWORD *)(*(_QWORD *)(result + 880) + 4LL) = -1;
        if ( a3 != 2 )
        {
          *(_DWORD *)(*(_QWORD *)(result + 856) + 8LL) = a2[2];
          *(_DWORD *)(*(_QWORD *)(result + 864) + 8LL) = -1;
          *(_DWORD *)(*(_QWORD *)(result + 872) + 8LL) = a2[2] - 1;
          *(_DWORD *)(*(_QWORD *)(result + 880) + 8LL) = -1;
        }
      }
      if ( a3 )
      {
        v4 = 0;
        do
        {
          v5 = *(_DWORD *)(*(_QWORD *)(result + 856) + 4 * v4);
          if ( v5 != -1 )
            *(_DWORD *)(*(_QWORD *)(result + 864) + 4LL * (unsigned int)(v5 - 1)) = v4;
          v6 = *(unsigned int *)(*(_QWORD *)(result + 872) + 4 * v4);
          if ( (_DWORD)v6 != -1 )
            *(_DWORD *)(*(_QWORD *)(result + 880) + 4 * v6) = v4;
          ++v4;
        }
        while ( a3 != v4 );
      }
    }
    v3 = 1;
  }
  *(_BYTE *)(*(_QWORD *)(result + 760) + 7844LL) = v3;
  *(_BYTE *)(*(_QWORD *)(result + 760) + 7845LL) = v3;
  *(_QWORD *)(*(_QWORD *)(result + 728) + 3680LL) = convert_host_pdev_id_to_target_pdev_id;
  *(_QWORD *)(*(_QWORD *)(result + 728) + 3688LL) = convert_target_pdev_id_to_host_pdev_id;
  *(_QWORD *)(*(_QWORD *)(result + 728) + 3696LL) = convert_host_phy_id_to_target_phy_id;
  *(_QWORD *)(*(_QWORD *)(result + 728) + 3704LL) = convert_target_phy_id_to_host_phy_id;
  return result;
}
