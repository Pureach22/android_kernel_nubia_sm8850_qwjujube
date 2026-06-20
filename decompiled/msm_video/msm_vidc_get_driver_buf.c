__int64 __fastcall msm_vidc_get_driver_buf(__int64 a1, __int64 a2)
{
  __int64 v3; // x21
  __int64 result; // x0
  __int64 v6; // x4
  int v7; // w8
  int v8; // w8
  __int64 (__fastcall **v9)(_QWORD); // x8
  __int64 (__fastcall *v10)(_QWORD); // x8
  __int64 v11; // x20
  __int64 v12; // x0

  v3 = *(_QWORD *)(a1 + 320);
  result = msm_vidc_fetch_buffer(a1, *(unsigned int *)(a2 + 12), *(unsigned int *)(a2 + 8));
  if ( !result )
  {
    if ( a1 && (msm_vidc_debug & 1) != 0 )
      printk(&unk_7F625, "err ", a1 + 340, "msm_vidc_get_driver_buf", v6);
    return 0;
  }
  if ( !a2 )
  {
    if ( (msm_vidc_debug & 1) != 0 )
      printk(&unk_83321, "err ", 0xFFFFFFFFLL, "codec", "vb2_buffer_to_driver");
    return 0;
  }
  *(_DWORD *)(result + 36) = *(_DWORD *)(a2 + 136);
  v7 = *(_DWORD *)(a2 + 144);
  *(_DWORD *)(result + 44) = v7;
  *(_DWORD *)(result + 48) = *(_DWORD *)(a2 + 120) - v7;
  *(_DWORD *)(result + 40) = *(_DWORD *)(a2 + 124);
  *(_QWORD *)(result + 72) = *(_QWORD *)(a2 + 24);
  v8 = *(_DWORD *)(a2 + 576);
  *(_DWORD *)(result + 80) = 1;
  *(_DWORD *)(result + 64) = v8;
  if ( *(_DWORD *)(a1 + 308) == 2 && *(_DWORD *)(result + 24) == 2 && (*(_BYTE *)(result + 112) & 1) == 0 )
  {
    if ( v3 && (v9 = *(__int64 (__fastcall ***)(_QWORD))(v3 + 6568)) != nullptr && (v10 = *v9) != nullptr )
    {
      v11 = result;
      if ( *((_DWORD *)v10 - 1) != 1935807271 )
        __break(0x8228u);
      v12 = v10(a1);
      *(_QWORD *)(v11 + 88) = v12;
      if ( v12 )
      {
        *(_BYTE *)(v11 + 112) |= 1u;
        return v11;
      }
    }
    else
    {
      *(_QWORD *)(result + 88) = 0;
    }
    return 0;
  }
  return result;
}
