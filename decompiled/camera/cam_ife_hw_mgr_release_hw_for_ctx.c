__int64 __fastcall cam_ife_hw_mgr_release_hw_for_ctx(__int64 result)
{
  __int64 v1; // x8
  __int64 v2; // x19
  __int64 v3; // x20
  __int64 v4; // x21
  _QWORD *v5; // x21
  _QWORD *v6; // x20
  _QWORD *v7; // x23
  _QWORD *v8; // x1
  _QWORD *v9; // x21
  _QWORD *v10; // x20
  _QWORD *v11; // x23
  _QWORD *v12; // x1
  __int64 v13; // x8
  __int64 v14; // x20
  __int64 v15; // x21
  _QWORD *v16; // x21
  _QWORD *v17; // x20
  _QWORD *v18; // x23
  _QWORD *v19; // x1
  _QWORD *v20; // x21
  _QWORD *v21; // x20
  _QWORD *v22; // x23
  _QWORD *v23; // x1
  char v24; // w8

  v1 = *(unsigned int *)(result + 8512);
  v2 = result;
  if ( (_DWORD)v1 )
  {
    v3 = v1 << 7;
    v4 = 0;
    do
    {
      result = cam_ife_hw_mgr_free_hw_res(*(_QWORD *)(v2 + 272) + v4, 0);
      v4 += 128;
      --*(_DWORD *)(v2 + 8512);
    }
    while ( v3 != v4 );
  }
  v5 = *(_QWORD **)(v2 + 256);
  if ( v5 != (_QWORD *)(v2 + 256) )
  {
    v6 = (_QWORD *)(v2 + 288);
    do
    {
      v7 = (_QWORD *)*v5;
      result = cam_ife_hw_mgr_free_hw_res(v5, 1);
      if ( v5 )
      {
        v8 = *(_QWORD **)(v2 + 296);
        if ( v5 == v6 || v8 == v5 || (_QWORD *)*v8 != v6 )
        {
          result = _list_add_valid_or_report(v5);
        }
        else
        {
          *(_QWORD *)(v2 + 296) = v5;
          *v5 = v6;
          v5[1] = v8;
          *v8 = v5;
        }
      }
      v5 = v7;
    }
    while ( v7 != (_QWORD *)(v2 + 256) );
  }
  v9 = *(_QWORD **)(v2 + 224);
  if ( v9 != (_QWORD *)(v2 + 224) )
  {
    v10 = (_QWORD *)(v2 + 288);
    do
    {
      v11 = (_QWORD *)*v9;
      result = cam_ife_hw_mgr_free_hw_res(v9, 1);
      if ( v9 )
      {
        v12 = *(_QWORD **)(v2 + 296);
        if ( v9 == v10 || v12 == v9 || (_QWORD *)*v12 != v10 )
        {
          result = _list_add_valid_or_report(v9);
        }
        else
        {
          *(_QWORD *)(v2 + 296) = v9;
          *v9 = v10;
          v9[1] = v12;
          *v12 = v9;
        }
      }
      v9 = v11;
    }
    while ( v11 != (_QWORD *)(v2 + 224) );
  }
  if ( *(_DWORD *)(v2 + 9312) == 2 )
  {
    v13 = *(unsigned int *)(v2 + 8516);
    if ( (_DWORD)v13 )
    {
      v14 = v13 << 7;
      v15 = 0;
      do
      {
        result = cam_ife_hw_mgr_free_hw_res(*(_QWORD *)(v2 + 280) + v15, 0);
        v15 += 128;
        --*(_DWORD *)(v2 + 8516);
      }
      while ( v14 != v15 );
    }
    v16 = *(_QWORD **)(v2 + 240);
    if ( v16 != (_QWORD *)(v2 + 240) )
    {
      v17 = (_QWORD *)(v2 + 288);
      do
      {
        v18 = (_QWORD *)*v16;
        result = cam_ife_hw_mgr_free_hw_res(v16, 1);
        if ( v16 )
        {
          v19 = *(_QWORD **)(v2 + 296);
          if ( v16 == v17 || v19 == v16 || (_QWORD *)*v19 != v17 )
          {
            result = _list_add_valid_or_report(v16);
          }
          else
          {
            *(_QWORD *)(v2 + 296) = v16;
            *v16 = v17;
            v16[1] = v19;
            *v19 = v16;
          }
        }
        v16 = v18;
      }
      while ( v18 != (_QWORD *)(v2 + 240) );
    }
  }
  v20 = *(_QWORD **)(v2 + 208);
  if ( v20 != (_QWORD *)(v2 + 208) )
  {
    v21 = (_QWORD *)(v2 + 288);
    do
    {
      v22 = (_QWORD *)*v20;
      result = cam_ife_hw_mgr_free_hw_res(v20, 1);
      if ( v20 )
      {
        v23 = *(_QWORD **)(v2 + 296);
        if ( v20 == v21 || v23 == v20 || (_QWORD *)*v23 != v21 )
        {
          result = _list_add_valid_or_report(v20);
        }
        else
        {
          *(_QWORD *)(v2 + 296) = v20;
          *v20 = v21;
          v20[1] = v23;
          *v23 = v20;
        }
      }
      v20 = v22;
    }
    while ( v22 != (_QWORD *)(v2 + 208) );
  }
  if ( *(_DWORD *)(v2 + 96) )
    result = cam_ife_hw_mgr_free_hw_res(v2 + 80, 1);
  *(_QWORD *)(v2 + 24) = 0;
  *(_QWORD *)(v2 + 32) = 0;
  v24 = debug_mdl;
  *(_QWORD *)(v2 + 9376) = 0;
  *(_QWORD *)(v2 + 9384) = 0;
  *(_QWORD *)(v2 + 9392) = 0;
  *(_DWORD *)(v2 + 9399) = 0;
  if ( (v24 & 8) != 0 && !debug_priority )
    return ((__int64 (*)(__int64, _QWORD, __int64, const char *, __int64, const char *, ...))cam_print_log)(
             3,
             v24 & 8,
             4,
             "cam_ife_hw_mgr_release_hw_for_ctx",
             2579,
             "release context completed ctx id:%u",
             *(_DWORD *)(v2 + 56));
  return result;
}
