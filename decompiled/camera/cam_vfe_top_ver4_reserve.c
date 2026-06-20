__int64 __fastcall cam_vfe_top_ver4_reserve(_DWORD *a1, __int64 a2)
{
  __int64 v2; // x19
  _DWORD *v3; // x22
  int v4; // w9
  unsigned int v5; // w8
  __int64 v6; // x20
  __int64 result; // x0
  int v8; // w7
  int v9; // w8
  int v10; // w10
  __int64 v11; // x20

  if ( !a1 || !a2 )
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      8,
      1,
      "cam_vfe_top_ver4_reserve",
      1321,
      "Error, Invalid input arguments");
    return 4294967274LL;
  }
  if ( (debug_mdl & 8) != 0 && !debug_priority )
  {
    v2 = a2;
    v3 = a1;
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      debug_mdl & 8,
      4,
      "cam_vfe_top_ver4_reserve",
      1330,
      "VFE:%u res id %d",
      *(_DWORD *)(*(_QWORD *)a1 + 4LL),
      *(_DWORD *)(a2 + 56));
    a1 = v3;
    a2 = v2;
    v4 = v3[272];
    if ( !v4 )
      return 4294967274LL;
  }
  else
  {
    v4 = a1[272];
    if ( !v4 )
      return 4294967274LL;
  }
  v5 = *(_DWORD *)(a2 + 56);
  if ( a1[7] == v5 )
  {
    v2 = (__int64)(a1 + 6);
    goto LABEL_8;
  }
  if ( v4 != 1 )
  {
    if ( a1[45] == v5 )
    {
      v2 = (__int64)(a1 + 44);
    }
    else
    {
      if ( v4 == 2 )
        return 4294967274LL;
      if ( a1[83] == v5 )
      {
        v2 = (__int64)(a1 + 82);
      }
      else
      {
        if ( v4 == 3 )
          return 4294967274LL;
        if ( a1[121] == v5 )
        {
          v2 = (__int64)(a1 + 120);
        }
        else
        {
          if ( v4 == 4 )
            return 4294967274LL;
          if ( a1[159] == v5 )
          {
            v2 = (__int64)(a1 + 158);
          }
          else
          {
            if ( v4 == 5 )
              return 4294967274LL;
            v10 = a1[197];
            if ( v10 == v5 )
            {
              v2 = (__int64)(a1 + 196);
            }
            else
            {
              if ( v4 == 6 )
                return 4294967274LL;
              if ( a1[235] != v5 )
              {
                if ( v4 == 7 )
                  return 4294967274LL;
                __break(0x5512u);
                goto LABEL_45;
              }
              v2 = (__int64)(a1 + 234);
            }
          }
        }
      }
    }
LABEL_8:
    v3 = *(_DWORD **)(v2 + 24);
    if ( *(_DWORD *)(v2 + 8) == 1 )
    {
      if ( v5 <= 9 && v5 - 3 <= 0xFFFFFFFD )
      {
        v6 = a2;
        cam_vfe_top_acquire_resource(v2, a2);
        a2 = v6;
      }
      result = 0;
      *(_QWORD *)(v2 + 48) = *(_QWORD *)(a2 + 72);
      *(_QWORD *)(v2 + 56) = *(_QWORD *)(a2 + 8);
      v3[5704] = *(_DWORD *)(a2 + 68);
      *(_DWORD *)(v2 + 8) = 2;
      goto LABEL_13;
    }
    if ( v5 )
    {
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        8,
        1,
        "cam_vfe_top_ver4_reserve",
        1342,
        "VFE:%d Duplicate acquire for camif",
        *(_DWORD *)(*(_QWORD *)a1 + 4LL));
      return 4294967274LL;
    }
    v8 = *(_DWORD *)(a2 + 68);
    v9 = v3[5704];
    if ( (v8 & v9) != 0 )
    {
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, _QWORD))cam_print_log)(
        3,
        8,
        1,
        "cam_vfe_top_ver4_reserve",
        1361,
        "VFE:%d Duplicate hw ctxt mask: 0x%x for camif curr_mask_val: 0x%x",
        *(unsigned int *)(*(_QWORD *)a1 + 4LL));
      return 4294967274LL;
    }
    LOBYTE(v10) = debug_mdl;
    if ( (debug_mdl & 8) == 0 || debug_priority )
    {
LABEL_28:
      result = 0;
      v3[5704] = v9 | v8;
LABEL_13:
      *(_QWORD *)(a2 + 48) = v2;
      return result;
    }
LABEL_45:
    v11 = a2;
    ((void (__fastcall *)(__int64, _QWORD, __int64, const char *, __int64, const char *, _QWORD))cam_print_log)(
      3,
      v10 & 8,
      4,
      "cam_vfe_top_ver4_reserve",
      1352,
      "VFE:%d Update hw ctxt mask: 0x%x for camif curr_mask_val: 0x%x",
      *(unsigned int *)(*(_QWORD *)a1 + 4LL));
    v8 = *(_DWORD *)(v11 + 68);
    a2 = v11;
    v9 = v3[5704];
    goto LABEL_28;
  }
  return 4294967274LL;
}
