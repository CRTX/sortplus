MODULES := src
CXXFLAGS = -std=c++17
LDFLAGS :=

include $(patsubst %,\
		%/module.mk,$(MODULES))

OBJ := \
		$(patsubst %.cpp,%.o, \
			$(filter %.cpp,$(SRC)))

sortplus: $(OBJ)
		$(CXX) -o $@ $(OBJ) $(LDFLAGS)

clean:
		$(RM) $(OBJ) sortplus
