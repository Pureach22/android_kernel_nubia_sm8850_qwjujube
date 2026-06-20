_QWORD *__fastcall cam_ife_csid_ver2_mini_dump(_QWORD *result, __int64 *a2)
{
  __int64 v3; // x8
  __int64 v4; // x23
  _QWORD *v5; // x20
  __int64 v6; // x24
  _DWORD *v7; // x25
  _QWORD *v8; // x8
  const void *v9; // x21
  __int64 v10; // x9
  __int64 v11; // x12
  __int64 v12; // x13
  __int64 v13; // x8
  __int64 v14; // x10
  __int64 v15; // x8
  __int64 v16; // x10

  if ( (unsigned __int64)a2[1] >= 0xEC0 )
  {
    v4 = *a2;
    v5 = result;
    v6 = 0;
    *(_QWORD *)(v4 + 3760) = result[4023];
    v7 = (_DWORD *)v4;
    *(_BYTE *)(v4 + 3768) = *(_DWORD *)(result[3891] + 92LL);
    do
    {
      v8 = &v5[v6];
      v9 = (const void *)v5[v6 + 3];
      if ( v9 )
      {
        *v7 = *((_DWORD *)v8 + 1);
        scnprintf(v7 + 1, 16, (const char *)v8 + 128);
        memcpy(v7 + 6, v9, 0x108u);
      }
      v6 += 19;
      v7 += 72;
    }
    while ( v6 != 228 );
    v10 = *(_QWORD *)((char *)v5 + 2092);
    v11 = *(_QWORD *)((char *)v5 + 2068);
    v12 = *(_QWORD *)((char *)v5 + 2076);
    *(_QWORD *)(v4 + 3492) = *(_QWORD *)((char *)v5 + 2084);
    *(_QWORD *)(v4 + 3500) = v10;
    *(_QWORD *)(v4 + 3476) = v11;
    *(_QWORD *)(v4 + 3484) = v12;
    v13 = *(_QWORD *)((char *)v5 + 2108);
    v14 = *(_QWORD *)((char *)v5 + 2116);
    LODWORD(v10) = *((_DWORD *)v5 + 531);
    *(_QWORD *)(v4 + 3508) = *(_QWORD *)((char *)v5 + 2100);
    *(_DWORD *)(v4 + 3532) = v10;
    *(_QWORD *)(v4 + 3516) = v13;
    *(_QWORD *)(v4 + 3524) = v14;
    v15 = *(_QWORD *)((char *)v5 + 2148);
    v16 = *(_QWORD *)((char *)v5 + 2156);
    *(_BYTE *)(v4 + 3472) = *((_BYTE *)v5 + 2164);
    *(_QWORD *)(v4 + 3464) = v16;
    *(_QWORD *)(v4 + 3456) = v15;
    result = memcpy((void *)(v4 + 3536), v5 + 228, 0xE0u);
    v3 = 3776;
  }
  else
  {
    v3 = 0;
  }
  a2[2] = v3;
  return result;
}
