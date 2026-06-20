_QWORD *__fastcall reg_alloc_and_fill_payload(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 psoc_obj; // x0
  double v7; // d0
  double v8; // d1
  double v9; // d2
  double v10; // d3
  double v11; // d4
  double v12; // d5
  double v13; // d6
  double v14; // d7
  _BYTE *v15; // x20
  _QWORD *result; // x0

  psoc_obj = reg_get_psoc_obj(a1);
  if ( psoc_obj )
  {
    v15 = (_BYTE *)psoc_obj;
    result = (_QWORD *)_qdf_mem_malloc(0x590u, "reg_alloc_and_fill_payload", 138);
    *(_QWORD *)a3 = result;
    if ( result )
    {
      *result = a1;
      *(_QWORD *)(*(_QWORD *)a3 + 8LL) = a2;
      if ( (reg_check_coex_unsafe_nb_user_prefer(a1) & 1) != 0 )
      {
        *(_BYTE *)(*(_QWORD *)a3 + 16LL) = v15[93273];
        qdf_mem_copy((void *)(*(_QWORD *)a3 + 20LL), v15 + 93276, 0x2A8u);
        v15[93273] = 0;
      }
      else
      {
        *(_BYTE *)(*(_QWORD *)a3 + 16LL) = v15[91680] != 0;
        qdf_mem_copy((void *)(*(_QWORD *)a3 + 20LL), v15 + 92404, 0x2A8u);
        v15[91680] = 0;
      }
      return qdf_mem_copy((void *)(*(_QWORD *)a3 + 700LL), v15 + 91684, 0x2D0u);
    }
  }
  else
  {
    result = (_QWORD *)qdf_trace_msg(
                         0x51u,
                         2u,
                         "%s: reg psoc private obj is NULL",
                         v7,
                         v8,
                         v9,
                         v10,
                         v11,
                         v12,
                         v13,
                         v14,
                         "reg_alloc_and_fill_payload");
    *(_QWORD *)a3 = 0;
  }
  return result;
}
