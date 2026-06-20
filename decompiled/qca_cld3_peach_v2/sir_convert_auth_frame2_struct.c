__int64 __fastcall sir_convert_auth_frame2_struct(__int64 a1, __int64 a2, unsigned int a3, __int64 a4)
{
  __int64 v8; // x5
  __int64 v9; // x6
  __int64 v10; // x7
  unsigned int v11; // w0
  double v12; // d0
  double v13; // d1
  double v14; // d2
  double v15; // d3
  double v16; // d4
  double v17; // d5
  double v18; // d6
  double v19; // d7
  size_t v20; // x2
  int v21; // w9
  int v22; // w8
  double v23; // d0
  double v24; // d1
  double v25; // d2
  double v26; // d3
  double v27; // d4
  double v28; // d5
  double v29; // d6
  double v30; // d7

  qdf_mem_set((void *)a4, 0x3FFu, 0);
  v11 = dot11f_unpack_authentication(a1, a2, a3, (__int64)&sir_convert_auth_frame2_struct_auth, 0, v8, v9, v10);
  if ( (v11 & 0x10000000) != 0 )
  {
    qdf_trace_msg(
      0x35u,
      2u,
      "%s: Failed to parse an Authentication frame (0x%08x, %d bytes):",
      v12,
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      "sir_convert_auth_frame2_struct",
      v11,
      a3);
    ((void (__fastcall *)(__int64, __int64, __int64, _QWORD))qdf_trace_hex_dump)(53, 2, a2, a3);
    return 16;
  }
  else
  {
    if ( v11 )
      qdf_trace_msg(
        0x35u,
        8u,
        "%s: There were warnings while unpacking an Authentication frame (0x%08x, %d bytes):",
        v12,
        v13,
        v14,
        v15,
        v16,
        v17,
        v18,
        v19,
        "sir_convert_auth_frame2_struct",
        v11,
        a3);
    *(_DWORD *)a4 = *(_DWORD *)&sir_convert_auth_frame2_struct_auth;
    *(_WORD *)(a4 + 4) = word_91E584;
    if ( byte_91E586 )
    {
      *(_BYTE *)(a4 + 6) = 16;
      v20 = (unsigned __int8)byte_91E587;
      *(_BYTE *)(a4 + 7) = byte_91E587;
      qdf_mem_copy((void *)(a4 + 8), &unk_91E588, v20);
    }
    v21 = (unsigned __int8)byte_91EE89;
    *(_BYTE *)(a4 + 1016) = byte_91EE89 != 0;
    if ( v21 && (unsigned __int8)byte_91EE8A >= 9u )
    {
      v22 = dword_91EE8E;
      *(_WORD *)(a4 + 1021) = word_91EE92;
      *(_DWORD *)(a4 + 1017) = v22;
    }
    if ( sir_convert_auth_frame2_struct_auth != 4 )
      return 0;
    if ( byte_91EE87 )
      *(_BYTE *)(a4 + 735) = byte_91EE88;
    if ( byte_91ED7D )
      qdf_mem_copy((void *)(a4 + 736), &unk_91ED7E, 8u);
    if ( byte_91ED6C )
      qdf_mem_copy((void *)(a4 + 1000), &unk_91ED6D, 0x10u);
    if ( byte_91ED86 )
    {
      qdf_mem_copy((void *)(a4 + 745), &unk_91ED88, (unsigned __int8)byte_91ED87);
      *(_BYTE *)(a4 + 744) = byte_91ED87;
    }
    if ( byte_91E685 )
    {
      qdf_mem_copy((void *)(a4 + 262), &unk_91E687, (unsigned __int8)byte_91E686);
      *(_BYTE *)(a4 + 261) = byte_91E686;
    }
    if ( byte_91E78A )
    {
      qdf_trace_msg(
        0x35u,
        8u,
        "%s: FT-FILS: r0kh_len:%d r1kh_present:%d",
        v12,
        v13,
        v14,
        v15,
        v16,
        v17,
        v18,
        v19,
        "update_ftie_in_fils_conf",
        (unsigned __int8)byte_91E813,
        (unsigned __int8)byte_91E7DD);
      *(_BYTE *)(a4 + 517) = 1;
      if ( byte_91E7DD )
        qdf_mem_copy((void *)(a4 + 599), &unk_91E7DE, 6u);
      if ( byte_91E812 )
      {
        qdf_mem_copy((void *)(a4 + 606), &unk_91E814, (unsigned __int8)byte_91E813);
        *(_BYTE *)(a4 + 605) = byte_91E813;
      }
      if ( *(_BYTE *)(a4 + 655) )
      {
        qdf_trace_msg(
          0x35u,
          8u,
          "%s: FT-FILS: GTK present",
          v23,
          v24,
          v25,
          v26,
          v27,
          v28,
          v29,
          v30,
          "update_ftie_in_fils_conf");
        qdf_mem_copy((void *)(a4 + 655), &unk_91E7E4, 0x2Eu);
      }
      if ( *(_BYTE *)(a4 + 701) )
      {
        qdf_trace_msg(
          0x35u,
          8u,
          "%s: FT-FILS: IGTK present",
          v23,
          v24,
          v25,
          v26,
          v27,
          v28,
          v29,
          v30,
          "update_ftie_in_fils_conf");
        qdf_mem_copy((void *)(a4 + 701), &unk_91E844, 0x22u);
      }
      qdf_mem_copy((void *)(a4 + 535), &unk_91E79D, 0x20u);
      qdf_mem_copy((void *)(a4 + 567), &unk_91E7BD, 0x20u);
      qdf_mem_copy((void *)(a4 + 519), &unk_91E78D, 0x10u);
      *(_BYTE *)(a4 + 518) = byte_91E78C;
      return 0;
    }
    else
    {
      return 0;
    }
  }
}
