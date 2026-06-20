void vi530x_setupAPIFunctions()
{
  _QWORD *v0; // x8

  *(_QWORD *)vi530x_func_tbl = VI530X_Chip_PowerON;
  v0 = (_QWORD *)vi530x_func_tbl;
  *(_QWORD *)(vi530x_func_tbl + 8) = VI530X_Chip_PowerOFF;
  v0[2] = VI530X_Set_Period;
  v0[3] = VI530X_Single_Measure;
  v0[4] = VI530X_Start_Continuous_Measure;
  v0[5] = VI530X_Stop_Continuous_Measure;
  v0[6] = VI530X_Get_Measure_Data;
  v0[7] = VI530X_Get_Interrupt_State;
  v0[8] = VI530X_Chip_Init;
  v0[9] = VI530X_Start_XTalk_Calibration;
  v0[10] = VI530X_Start_Offset_Calibration;
  v0[11] = VI530X_Get_XTalk_Parameter;
  v0[12] = VI530X_Config_XTalk_Parameter;
}
