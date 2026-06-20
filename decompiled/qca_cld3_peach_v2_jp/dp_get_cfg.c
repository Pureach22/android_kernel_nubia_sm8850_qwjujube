__int64 __fastcall dp_get_cfg(__int64 a1, int a2)
{
  __int64 result; // x0

  result = 0;
  switch ( a2 )
  {
    case 0:
      result = *(unsigned int *)(*(_QWORD *)(a1 + 40) + 628LL);
      break;
    case 1:
      result = *(unsigned __int8 *)(*(_QWORD *)(a1 + 40) + 546LL);
      break;
    case 2:
      result = *(unsigned __int8 *)(*(_QWORD *)(a1 + 40) + 547LL);
      break;
    case 3:
      result = *(unsigned __int8 *)(*(_QWORD *)(a1 + 40) + 548LL);
      break;
    case 4:
      result = *(unsigned __int8 *)(*(_QWORD *)(a1 + 40) + 549LL);
      break;
    case 5:
      result = *(unsigned __int8 *)(*(_QWORD *)(a1 + 40) + 529LL);
      break;
    case 6:
      result = *(unsigned __int8 *)(*(_QWORD *)(a1 + 40) + 530LL);
      break;
    case 7:
      result = *(unsigned __int8 *)(*(_QWORD *)(a1 + 40) + 532LL);
      break;
    case 8:
      result = *(unsigned __int8 *)(*(_QWORD *)(a1 + 40) + 533LL);
      break;
    case 9:
      result = *(unsigned int *)(*(_QWORD *)(a1 + 40) + 536LL);
      break;
    case 10:
      result = *(unsigned __int8 *)(*(_QWORD *)(a1 + 40) + 531LL);
      break;
    case 11:
      result = *(unsigned int *)(*(_QWORD *)(a1 + 40) + 560LL);
      break;
    case 12:
      result = *(unsigned int *)(*(_QWORD *)(a1 + 40) + 556LL);
      break;
    case 19:
      result = *(unsigned __int8 *)(*(_QWORD *)(a1 + 40) + 632LL);
      break;
    case 20:
      result = *(unsigned __int8 *)(*(_QWORD *)(a1 + 40) + 712LL);
      break;
    case 21:
      result = *(unsigned __int8 *)(*(_QWORD *)(a1 + 40) + 755LL);
      break;
    case 22:
      result = *(unsigned __int8 *)(*(_QWORD *)(a1 + 40) + 817LL);
      break;
    default:
      return result;
  }
  return result;
}
