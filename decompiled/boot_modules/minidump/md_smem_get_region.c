__int64 __usercall md_smem_get_region@<X0>(__int64 s2@<X0>, _QWORD *a2@<X8>)
{
  __int64 v3; // x22
  const char *v4; // x20
  __int64 v5; // x23
  const char *v6; // x21
  __int64 v7; // x9
  __int64 v8; // x10
  __int64 v9; // x8

  v3 = (unsigned int)md_num_regions;
  a2[4] = 0;
  a2[5] = 0;
  a2[2] = 0;
  a2[3] = 0;
  *a2 = 0;
  a2[1] = 0;
  if ( (int)v3 >= 1 )
  {
    v4 = (const char *)s2;
    v5 = 0;
    v6 = (const char *)&unk_110100;
    while ( v5 != 202 )
    {
      s2 = strcmp(v6, v4);
      if ( !(_DWORD)s2 )
      {
        v7 = *((_QWORD *)v6 + 3);
        a2[2] = *((_QWORD *)v6 + 2);
        a2[3] = v7;
        v8 = *((_QWORD *)v6 + 5);
        a2[4] = *((_QWORD *)v6 + 4);
        a2[5] = v8;
        v9 = *((_QWORD *)v6 + 1);
        *a2 = *(_QWORD *)v6;
        a2[1] = v9;
        return s2;
      }
      ++v5;
      v6 += 48;
      if ( v3 == v5 )
        return s2;
    }
    __break(0x5512u);
    return md_add_ss_toc((char *)s2);
  }
  return s2;
}
